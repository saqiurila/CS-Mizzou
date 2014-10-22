typedef struct node_ {
    int data;
    struct node_* next;
}Set;

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
 * This prelab you will implement a linkedlist that
 * represents a mathematical set; ie no duplicates
 *
 * When inserting into the set, you must first confirm that the
 * data is not currently in the set. If it is not, then it should be 
 * inserted into the head of the list. Otherwise, the head of the set
 * should be returned unchanged. 
 */
Set* insert(Set* set, int data);
void print(Set* set);

int main(void) {

    Set* set = NULL;

    set = insert(set, 1);

    assert(set != NULL);
    assert(set->data == 1);
    
    set = insert(set, 2);

    assert(set->data == 2);
    
    set = insert(set, 1);

    assert(set->data == 2);
    assert(set->next->data == 1);
    assert(set->next->next == NULL);

	print(set);
    printf("You have completed the prelab\n");
}

Set* insert(Set* set, int data){
	Set* temp=set;
	Set* head;
	while(temp!=NULL){
		if(temp->data==data){
			return set;
		}
		temp=temp->next;
	}
	head=(Set*)malloc(sizeof(Set));
	head->data=data;
	head->next=set;
	return head;
}

void print(Set* set){
	Set* temp=set;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}