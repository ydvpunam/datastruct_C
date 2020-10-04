#include <stdio.h>
#include <malloc.h>
#include "list.h"

struct Student_T* create_list() // O[1]
{
	struct Student_T* iterator = (struct Student_T*) calloc(1, sizeof(struct Student_T));
	iterator->number = 0;
	return iterator;
}

void add_node(struct Student_T* iterator) //O[n]
{
	if (iterator != NULL)
	{
		while(iterator->next != NULL)
			iterator = iterator->next;
		iterator->next = (struct Student_T*) calloc(1, sizeof(struct Student_T));
		iterator->next->number = iterator->number + 1;
	}
	return;
}

void print_list(struct Student_T* iterator) //O[n]
{
	printf("The complete list is : \t");
	while (iterator != NULL)
	{
		printf("%lu\t\t", iterator->number);
		iterator = iterator->next;
	}
	printf("%\n");
	fflush(stdout);
	return;
}

void remove_node(struct Student_T* iterator) // O[n]
{
	if (iterator != NULL && iterator->next != NULL)
	{
		while(iterator->next->next != NULL)
			iterator = iterator->next;
		free_node(iterator->next);
		iterator->next = NULL;
	}
	return;
}

void delete_list(struct Student_T** p_iterator) // O[n]
{
	if (p_iterator != NULL && *p_iterator != NULL) //Check to break Recursion
	{
		delete_list(&((*p_iterator)->next)); //Recursion
		free_node(*p_iterator); //Action
		*p_iterator = NULL; //This will set the actual head pointer to NULL
	}
	return;
}

int count_node(struct Student_T* iterator) // O[n]
{
	int count = 0;
	if (iterator != NULL)
	{
		while (iterator != NULL)
		{
			iterator = iterator->next;
			count++;
		}
	}
	return count;
}

void delete_node_at(struct Student_T* iterator, const unsigned long pos) // O[n]
{
	int count = 0;
	if (iterator != NULL && pos < count_node(iterator))
	{
		for(count=0; count<pos-1; count++)
			iterator = iterator->next;
		// 1st technique
		struct Student_T* link = iterator->next->next;
		free_node(iterator->next);
		iterator->next = link;
		
		// 2nd technique
		/*struct Student_T* waste = iterator->next;
		iterator->next = iterator->next->next;
		free_node(waste);*/
	}
	return;
}

void remove_head(struct Student_T** p_iterator) // O[1]
{
	if (p_iterator != NULL && *p_iterator != NULL)
	{
		struct Student_T* head = *p_iterator;
		*p_iterator = (*p_iterator)->next;
		free_node(head);
	}
	return;
}

void insert_node_at(struct Student_T* iterator, struct Student_T* node, const unsigned long pos) // O[n]
{
	int count = 0;
	if(iterator != NULL && pos <= count_node(iterator))
	{
		int a;
		for(count=0; count<pos-1; count++)
			iterator = iterator->next;
		node->next = iterator->next;
		iterator->next = node;
	}
	
	return;
}

void store_list(FILE* handle, struct Student_T* iterator) //O[n]
{
	if(handle != NULL && iterator != NULL)
	{
		while(iterator != NULL)
		{
			fwrite(iterator, sizeof(struct Student_T), 1, handle);
			iterator = iterator->next;
		}
	}
	return;
}

struct Student_T* load_list(FILE* handle) //O[n]
{
	struct Student_T *iterator = NULL, *head = NULL;
	if (handle != NULL)
	{
		head = (struct Student_T*)calloc(1, sizeof(struct Student_T));
		fread(head, sizeof(struct Student_T), 1, handle);
		if (head != NULL)
		{
			iterator = head;
			iterator->next = (struct Student_T*)calloc(1, sizeof(struct Student_T));
			while(fread(iterator->next, sizeof(struct Student_T), 1, handle))
			{
				iterator = iterator->next;
				iterator->next = (struct Student_T*)calloc(1, sizeof(struct Student_T));
			}
			free_node(iterator->next);
			iterator->next = NULL;
		}
	}
	return head;	
}

struct Student_T* find_node(struct Student_T* iterator, const unsigned long number)
{
	while(iterator != NULL)
	{
		if (iterator->number == number)
			break;
		iterator = iterator->next;
	}
	
	return iterator;
}

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