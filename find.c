#include<stdio.h>
#include<malloc.h>

struct student_t
{
	int rno;
	int num;
	char name; // Added by praveen
	struct student_t* next;
};

struct student_t *head; // Moved from below

struct student_t* create_list()
{
	struct student_t* temp=(struct student_t*)calloc(1, sizeof(struct student_t));
	temp->num=0;
	temp->rno=1;
	temp->name = 'A'; 
	return temp;
} //; // Semicolon is not needed

int count_node(struct student_t* temp)
{
	int count = 0;
	//if (temp != NULL) // Commented by Swastik
	//{
		while (temp != NULL)
		{
			temp = temp->next;
			count++;
		}
	//}
	return count;
}

void print_list(struct student_t* temp)
{
	printf("The complete list is as follows: \t");
	while (temp != NULL)
	{
		printf("%d  %d  %c\t", temp->num, temp->rno, temp->name); // Modified by praveen
		temp = temp->next;
	}
	printf("%\n");
	return;
}

void add_node(struct student_t* temp)
{
	if(temp != NULL)
	{
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = (struct student_t*)calloc(1, sizeof(struct student_t));
		temp->next->num = (temp->num) + 1;
		temp->next->rno = (temp->rno) + 1;
		temp->next->name = (temp->name + 1); // Added by praveen
	}
	return;
}

// Commented by Swastik
/*void find_rno(struct student_t* temp) 
{
	for (int i=0; i<=count_node(temp); i++)
	{
		if (temp->num == 1)
		{
			printf("%d", temp->rno);
		}
	}
	return ;
}*/

// Added by Swastik
struct student_t* find_rno(struct student_t* temp, int rno)
{
	while(temp != NULL)
	{
		if (temp->rno == rno)
			break;
		temp = temp->next;
	}
	
	return temp;
}

int main()
{
	head = create_list();
	add_node(head);
	add_node(head);
	add_node(head);
	add_node(head);
	add_node(head);
	add_node(head);
	add_node(head);
	print_list(head);
	//find_rno(head);
	struct student_t* found = find_rno(head, 4); // Added by praveen
	if (found != NULL)
		printf("Found roll no. is %d  %d  %c\t", found->num, found->rno, found->name);
	printf("%c", NULL);
	return 0;
}
