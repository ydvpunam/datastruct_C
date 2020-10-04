#include <stdio.h>
#include <signal.h>
#include <malloc.h>
#include "list.h"

FILE *storage = NULL;
struct Student_T* head = NULL;

static void catch_signal(int signo) {
	if (signo == SIGINT)
	{
		storage = fopen ("list.dat", "a");
		if(storage != NULL)
			store_list(storage, head);
		fclose(storage);
		exit(1);
	}
}

int main()
{
	if (signal(SIGINT, catch_signal) == SIG_ERR) {
        fprintf(stderr, "An error occurred while setting a signal handler.\n");
        return 1;
    }
	
	if(0)
		printf("Val of Null is : %d\n", NULL);
	printf("Val of Expression is %d\n", 2==2);
	unsigned char option = 0;
	unsigned long pos = 0;
	while(option<=10)
	{
		printf("Create List --> 1\n");
		printf("Add Node --> 2\n");
		printf("Remove Node --> 3\n");
		printf("Insert Node At --> 4\n");
		printf("Delete Node At --> 5\n");
		printf("Remove Head --> 6\n");
		printf("Delete List --> 7\n");
		printf("Print List --> 8\n");
		printf("Store List --> 9\n");
		printf("Load List --> 10\n");
		printf("Enter option: ");
		fflush(stdout);
		fflush(stdin);
		scanf("%d", &option);
		
		switch(option)
		{
			case 1:
				if (head == NULL)
					head = create_list();
				print_list(head);
				break;
			
			case 2:
				add_node(head);
				print_list(head);
				break;
				
			case 3:
				remove_node(head);
				print_list(head);
				break;
				
			case 4:
				printf("Enter position of the node to be inserted: ");
				fflush(stdout);
				fflush(stdin);
				scanf("%d", &pos);
				struct Student_T* node = (struct Student_T*) calloc(1, sizeof(struct Student_T));
				node->number = count_node(head);
				insert_node_at(head, node, pos-1);
				print_list(head);
				break;
				
			case 5:
				printf("Enter position of the node to be deleted: ");
				fflush(stdout);
				fflush(stdin);
				scanf("%d", &pos);
				delete_node_at(head, pos-1);
				print_list(head);
				break;
				
			case 6:
				remove_head(&head);
				print_list(head);
				break;
				
			case 7:
				delete_list(&head);
				break;
			
			case 8:
				print_list(head);
				break;
				
			case 9:
				storage = fopen("list.dat", "w");
				if(storage != NULL)
				{
					store_list(storage, head);
					fclose(storage);
				}
				break;
			
			case 10:
				if (head == NULL)
				{
					storage = fopen ("list.dat", "r");
					if(storage != NULL)
					{
						head = load_list(storage);
						fclose(storage);
						print_list(head);
					}
				}
				break;
				
			default:
				break;
		}
		system("pause");
	}
	
	return 0;
}