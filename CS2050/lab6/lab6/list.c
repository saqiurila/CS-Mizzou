/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 15
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

node* insert_at_head(node* list,int data){
	node* newhead=malloc(sizeof(node));
	newhead->data=data;
	newhead->next=list;
	list=newhead;
	return list;
}
void print_list(node* list){
	node* current=list;
	if(list==NULL){
		printf("Successfully free the list! It is empty now.\n");
		return;
	}
	while(current!=NULL){
		printf("%d -> ",current->data);
		current=current->next;
	}
	printf("NULL\n");
}
void free_list(node* list){
	node* temp;
	node* current=list;
	while(current!=NULL){
		temp=current;
		current=current->next;
		free(temp);
	}
}
node* reverse_list(node *head){
    if (head==NULL){
        return NULL;
    }
    node *temp = reverse_list(head->next);
    if (temp==NULL){
        return head;
    }
    head->next->next = head; //reverse
    head->next = NULL; //"next" of the first node is NULL

    return temp;
}



