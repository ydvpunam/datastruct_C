#pragma once

struct Date_T
{
	unsigned char day;
	unsigned char month;
	unsigned short year;
};

struct Student_T
{
	unsigned long number;
	char* name;
	char* entry_no;
	char* branch;
	unsigned char semester;
	struct Date_T dob;
	struct Student_T *next;
};

struct Student_T* create_list();
void add_node(struct Student_T* iterator);
void print_list(struct Student_T* iterator);
void remove_node(struct Student_T* iterator);
void delete_list(struct Student_T** p_iterator);
int count_node(struct Student_T* iterator);
void delete_node_at(struct Student_T* iterator, const unsigned long pos);
void remove_head(struct Student_T** p_iterator);
void insert_node_at(struct Student_T* iterator, struct Student_T* node, const unsigned long pos);
void store_list(FILE* handle, struct Student_T* iterator);
struct Student_T* load_list(FILE* handle);
struct Student_T* find_node(struct Student_T* iterator, const unsigned long number); // ASSIGNMENT (Write Definition)
static void free_node(struct Student_T* node);