#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "queue.h"

Queue* print(Queue* queue); 

int main(int argc,char* argv[]) {
	if(argc!=2){
		printf("Usage:./printer input.txt.");
		return 0;
	}
	int i=0;
	//printf("%d\n",i++);
	FILE* fp=fopen(argv[1],"r");
	Queue* queue;
	char string[200];
	while(fgets(string,200,fp)!=NULL){
		queue=enqueue(queue,string);
		//printf("%s",string);
		//print_list(queue);
		if(size(queue)>=3){
			queue=print(queue);
		}
	}
	print(queue);
}

Queue* print(Queue* queue){
	sleep(1);
	int i=size(queue);
	char* string;
	while(i-->0){
		//printf("before:%s\n",queue->data);
		string=dequeue(&queue);
		printf("%s",string);
		//printf("after:%s\n",queue->data);
	}
	printf("\n");
	return queue;
}