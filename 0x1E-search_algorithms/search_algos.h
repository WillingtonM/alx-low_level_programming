#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 * struct listint_s - singly linked list
 *
 * @n: Integer
 * @index: Index of node in list
 * @next: Pointer to next node
 * Description: singly linked list node structure for project
 */
typedef struct listint_s
{
	int n;
	size_t index;
	struct listint_s *next;
} listint_t;

/**
 * struct skiplist_s - Singly linked list with express lane
 * @n: Integer
 * @index: Index of node in list
 * @next: Pointer to next node
 * @express: Pointer to next node in express lane
 * Description: singly linked list node structure with express lane
 * for project
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

int binary_search(int *array, size_t size, int value);
int linear_search(int *array, size_t size, int value);
int interpolation_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int bin_search(int *array, size_t left, size_t right, int value);
int advanced_binary(int *array, size_t size, int value);
int rec_search(int *array, size_t size, int value);
int exponential_search(int *array, size_t size, int value);
skiplist_t *linear_skip(skiplist_t *list, int value);
listint_t *jump_list(listint_t *list, size_t size, int value);

#endif
