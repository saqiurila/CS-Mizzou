/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 22
*/
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set* set_insert(Set* list,int data){
	Set* temp=list;
	Set* head;
	//Check if the data is already in the set
	while(temp!=NULL){
		if(temp->data==data){
			return list;
		}
		temp=temp->next;
	}
	//malloc a new head
	head=(Set*)malloc(sizeof(Set));
	head->data=data;
	head->next=list;
	return head;
}
Set* set_remove(Set* list,int data){
	Set* current;
	Set* temp;
	//if the data of the head of the list is equal to data
	if(list->data==data){
		temp=list->next;
		free(list);
		return temp;
	}
	current=list;
	while(current!=NULL){
		if(current->next->data==data){
			//delete current->next
			temp=current->next;
			current->next=current->next->next;
			free(temp);
			return list;
		}
		else{
			current=current->next;
		}
	}
	return list;
}
Set* set_intersection(Set* first,Set* second){
	Set* intersection=NULL;
	Set* current=first;
	Set* temp=second;
	//Compare each element in first with every element in second
	while(current!=NULL){
		while(temp!=NULL){
			if(current->data==temp->data){
				break;
			}
			temp=temp->next;
		}
		//if current data is in both linked list, insert it into intersection
		if(temp!=NULL){
			intersection=set_insert(intersection,current->data);
		}
		current=current->next;
	}
	return intersection;
}
void print_list(Set* list){
	Set* current=list;
	while(current!=NULL){
		printf("%d -> ",current->data);
		current=current->next;
	}
	printf("NULL\n");
}
void free_list(Set* list){
	Set* temp;
	Set* current=list;
	while(current!=NULL){
		temp=current;
		current=current->next;
		free(temp);
	}
}
int getMiddle(Set* list){
	Set* slowPtr=list;
	Set* fastPtr=list;
	//fastPtr move two times faster than slowPtr
	while (fastPtr!=NULL&&fastPtr->next!=NULL){
		fastPtr=fastPtr->next->next;
		slowPtr=slowPtr->next;
	}
	return slowPtr->data;
}