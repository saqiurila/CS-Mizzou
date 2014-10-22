/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 15
*/
#ifndef LIST_H_
#define LIST_H_

typedef struct node_{
	int data;
	struct node_* next;
}node;

node* insert_at_head(node* list,int data);
void print_list(node* list);
void free_list(node* list);
node* create_list(char* file);
node* reverse_list(node *head); //bonus

#endif