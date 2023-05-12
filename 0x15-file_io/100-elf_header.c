#include <elf.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/**
 * check_elf - Checks if a file is an ELF file.
 * @elf_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: error code 98 If the file is not ELF file.
 */
void check_elf(unsigned char *elf_ident)
{
    int index_n;

    for (index_n = 0; index_n < 4; index_n++)
    {
        if (elf_ident[index_n] != 127 &&
            elf_ident[index_n] != 'E' &&
            elf_ident[index_n] != 'L' &&
            elf_ident[index_n] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

/**
 * printf_class - Prints class of ELF header.
 * @elf_ident: A pointer to array containing ELF class.
 */
void printf_class(unsigned char *elf_ident)
{
    printf("  Class:                             ");

    switch (elf_ident[EI_CLASS])
    {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("ELF64\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
    }
}

/**
 * printf_magic - Prints out magic numbers of ELF header.
 * @elf_ident: Pointer to array containing ELF magic numbers.
 *
 * Description: Magic numbers separated by spaces.
 */
void printf_magic(unsigned char *elf_ident)
{
    int index_n;

    printf("  Magic:   ");

    for (index_n = 0; index_n < EI_NIDENT; index_n++)
    {
        printf("%02x", elf_ident[index_n]);

        if (index_n == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printf_data - Prints data of ELF header.
 * @elf_ident: Pointer to array containing ELF class.
 */
void printf_data(unsigned char *elf_ident)
{
    printf("  Data:                              ");

    switch (elf_ident[EI_DATA])
    {
    case ELFDATANONE:
        printf("none\n");
        break;
    case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
    case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_ident[EI_CLASS]);
    }
}

/**
 * printf_version - Prints version of ELF header.
 * @elf_ident: Pointer to array containing ELF version.
 */
void printf_version(unsigned char *elf_ident)
{
    printf("  Version:                           %d",
           elf_ident[EI_VERSION]);

    switch (elf_ident[EI_VERSION])
    {
    case EV_CURRENT:
        printf(" (current)\n");
        break;
    default:
        printf("\n");
        break;
    }
}

/**
 * printf_abi - Print ABI version of ELF header.
 * @elf_ident: Pointer to array containing ELF ABI version.
 */
void printf_abi(unsigned char *elf_ident)
{
    printf("  ABI Version:                       %d\n",
           elf_ident[EI_ABIVERSION]);
}

/**
 * printf_type - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void printf_type(unsigned int elf_type, unsigned char *elf_ident)
{
    if (elf_ident[EI_DATA] == ELFDATA2MSB)
        elf_type >>= 8;

    printf("  Type:                              ");

    switch (elf_type)
    {
    case ET_NONE:
        printf("NONE (None)\n");
        break;
    case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
    case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
    case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
    case ET_CORE:
        printf("CORE (Core file)\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_type);
    }
}


/**
 * printf_osabi - Print OS/ABI of ELF header.
 * @elf_ident: Pointer to array containing ELF version.
 */
void printf_osabi(unsigned char *elf_ident)
{
    printf("  OS/ABI:                            ");

    switch (elf_ident[EI_OSABI])
    {
    case ELFOSABI_NONE:
        printf("UNIX - System V\n");
        break;
    case ELFOSABI_HPUX:
        printf("UNIX - HP-UX\n");
        break;
    case ELFOSABI_NETBSD:
        printf("UNIX - NetBSD\n");
        break;
    case ELFOSABI_LINUX:
        printf("UNIX - Linux\n");
        break;
    case ELFOSABI_SOLARIS:
        printf("UNIX - Solaris\n");
        break;
    case ELFOSABI_IRIX:
        printf("UNIX - IRIX\n");
        break;
    case ELFOSABI_FREEBSD:
        printf("UNIX - FreeBSD\n");
        break;
    case ELFOSABI_TRU64:
        printf("UNIX - TRU64\n");
        break;
    case ELFOSABI_ARM:
        printf("ARM\n");
        break;
    case ELFOSABI_STANDALONE:
        printf("Standalone App\n");
        break;
    default:
        printf("<unknown: %x>\n", elf_ident[EI_OSABI]);
    }
}

/**
 * close_elf - Closes an ELF file.
 * @elf: File descriptor of ELF file.
 *
 * Description: exit code 98 If file cannot be closed.
 */
void close_elf(int elf)
{
    if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
                "Error: Can't close fd %d\n", elf);
        exit(98);
    }
}

/**
 * print_entry - Print entry point of ELF header.
 * @elf_entry: Address of ELF entry point.
 * @elf_ident: Pointer to array containing ELF class.
 */
void print_entry(unsigned long int elf_entry, unsigned char *elf_ident)
{
    printf("  Entry point address:               ");

    if (elf_ident[EI_DATA] == ELFDATA2MSB)
    {
        elf_entry = ((elf_entry << 8) & 0xFF00FF00) |
                  ((elf_entry >> 8) & 0xFF00FF);
        elf_entry = (elf_entry << 16) | (elf_entry >> 16);
    }

    if (elf_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)elf_entry);

    else
        printf("%#lx\n", elf_entry);
}

/**
 * main - Shows info in the ELF header at start of ELF file.
 * @argc: Number of arguments supplied.
 * @argv: Array of pointers to arguments.
 *
 * Description: exit code 98 If file not ELF or the function fails.
 *
 * Return: Return 1 if it success
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
    Elf64_Ehdr *header;

    int fo, fr;

    fo = open(argv[1], O_RDONLY);

    if (fo == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    header = malloc(sizeof(Elf64_Ehdr));

    if (header == NULL)
    {
        close_elf(fo);
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
    }

    fr = read(fo, header, sizeof(Elf64_Ehdr));

    if (fr == -1)
    {
        free(header);
        close_elf(fo);
        dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
        exit(98);
    }

    check_elf(header->elf_ident);
    printf("ELF Header:\n");
    printf_magic(header->elf_ident);
    printf_class(header->elf_ident);
    printf_data(header->elf_ident);
    printf_version(header->elf_ident);
    printf_osabi(header->elf_ident);
    printf_abi(header->elf_ident);
    printf_type(header->elf_type, header->elf_ident);
    print_entry(header->elf_entry, header->elf_ident);

    free(header);

    close_elf(fo);

    return (0);
}
