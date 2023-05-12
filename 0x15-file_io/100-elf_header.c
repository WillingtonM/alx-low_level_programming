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
void check_elf(unsigned char *e_ident)
{
    int index;

    for (index = 0; index < 4; index++)
    {
        if (e_ident[index] != 127 &&
            e_ident[index] != 'E' &&
            e_ident[index] != 'L' &&
            e_ident[index] != 'F')
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
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");

    switch (e_ident[EI_CLASS])
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
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printf_magic - Prints out magic numbers of ELF header.
 * @elf_ident: Pointer to array containing ELF magic numbers.
 *
 * Description: Magic numbers separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
    int index;

    printf("  Magic:   ");

    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", e_ident[index]);

        if (index == EI_NIDENT - 1)
            printf("\n");
        else
            printf(" ");
    }
}

/**
 * printf_data - Prints data of ELF header.
 * @elf_ident: Pointer to array containing ELF class.
 */
void print_data(unsigned char *e_ident)
{
    printf("  Data:                              ");

    switch (e_ident[EI_DATA])
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
        printf("<unknown: %x>\n", e_ident[EI_CLASS]);
    }
}

/**
 * printf_version - Prints version of ELF header.
 * @elf_ident: Pointer to array containing ELF version.
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:                           %d",
           e_ident[EI_VERSION]);

    switch (e_ident[EI_VERSION])
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
void print_abi(unsigned char *e_ident)
{
    printf("  ABI Version:                       %d\n",
           e_ident[EI_ABIVERSION]);
}

/**
 * printf_type - Prints the type of an ELF header.
 * @elf_type: The ELF type.
 * @elf_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
    if (e_ident[EI_DATA] == ELFDATA2MSB)
        e_type >>= 8;

    printf("  Type:                              ");

    switch (e_type)
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
        printf("<unknown: %x>\n", e_type);
    }
}

/**
 * printf_osabi - Print OS/ABI of ELF header.
 * @elf_ident: Pointer to array containing ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
    printf("  OS/ABI:                            ");

    switch (e_ident[EI_OSABI])
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
        printf("<unknown: %x>\n", e_ident[EI_OSABI]);
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
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
    printf("  Entry point address:               ");

    if (e_ident[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
                  ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
    }

    if (e_ident[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);

    else
        printf("%#lx\n", e_entry);
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
