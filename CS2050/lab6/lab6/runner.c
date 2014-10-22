/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 15
*/
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc,char* argv[]){	
	node* list=create_list(argv[1]); //create
	printf("\n");
	print_list(list);
	printf("\n");
	
	list=reverse_list(list); //reverse
	printf("Bonus:\n");
	print_list(list);
	printf("\n");
	
	free_list(list); //free
	list=NULL;
	print_list(list);
	printf("\n");
}
node* create_list(char* file){
	FILE* fp=fopen(file,"r");
	node* start=NULL;
	int data;
	while(1){
		fscanf(fp,"%d",&data);
		start=insert_at_head(start,data);
		if(feof(fp)){
			break;
		}
	}
	return start;
}
