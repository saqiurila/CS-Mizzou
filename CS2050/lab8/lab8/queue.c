#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue* enqueue(Queue* queue,char* data){
	Queue* newElement=(Queue*)malloc(sizeof(Queue));
	Queue* current=queue;
	
	newElement->data=malloc((strlen(data)+1)*sizeof(char));
	strcpy(newElement->data,data);
	//printf("Enqueueing: %s",newElement->data);
	newElement->next=NULL;
	
	if(queue==NULL){
		return newElement;
	}
	while(current->next!=NULL){
		current=current->next;
	}	
	current->next=newElement;
	return queue;
}
char* dequeue(Queue** queue){
	Queue* temp;
	char* string;
	if(*queue==NULL){
		string="null";
	}
	else if((*queue)->next==NULL){
		temp=*queue;
		string=temp->data;
		//printf("dequeueing3:%s\n",temp->data);
		*queue=NULL;
		free(temp);
	}
	else{
		temp=*queue;
		//printf("dequeueing1:%s\n",(*queue)->data);
		//printf("dequeueing2:%s\n",temp->data);
		string=temp->data;
		*queue=(*queue)->next;
		free(temp);
	}
	return string;
}
int size(Queue* queue){
	int size=0;
	Queue* current=queue;
	while(current!=NULL){
		size++;
		current=current->next;
	}
	return size;
}