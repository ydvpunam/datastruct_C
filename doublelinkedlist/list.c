#include <stdio.h>
#include <malloc.h>
#include "list.h"

struct Student_T* create_list()
{
	struct Student_T* head = (struct Student_T*) calloc(1, sizeof(struct Student_T));
	head->number = 0;
	return head;
}

void add_node(struct Student_T* iterator)
{
	if(iterator)
	{
		while(iterator->next)
			iterator = iterator->next;
		iterator->next = (struct Student_T*) calloc(1, sizeof(struct Student_T));;
		iterator->next->previous = iterator;
		iterator->next->number = iterator->number + 1;
	}
	return;
}

void print_list(struct Student_T* iterator) //O[n]
{
	printf("The complete list is : \t");
	while (iterator)
	{
		printf("%lu\t\t", iterator->number);
		iterator = iterator->next;
	}
	printf("%\n");
	fflush(stdout);
	return;
}

void remove_node(struct Student_T* iterator)
{
	if(iterator && iterator->next)
	{
		while(iterator->next->next)
			iterator = iterator->next;
		free_node(iterator->next);
		iterator->next == NULL;
	}
		
	return;
}

void delete_list(struct Student_T** p_iterator)
{}
int count_node(struct Student_T* iterator){}
void delete_node_at(struct Student_T* iterator, const unsigned long pos)
{}
void remove_head(struct Student_T** p_iterator)
{}
void insert_node_at(struct Student_T* iterator, struct Student_T* node, const unsigned long pos)
{}
void store_list(FILE* handle, struct Student_T* iterator)
{}
struct Student_T* load_list(FILE* handle)
{}
struct Student_T* find_node(struct Student_T* iterator, const unsigned long number)
{}

static void free_node(struct Student_T* node)
{
	if (node)
	{
		free(node->name);
		free(node->entry_no);
		free(node->branch);
		free(node);
	}
	return;
}
