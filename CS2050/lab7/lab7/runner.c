/**
*FNU Saqiurila
*14227763
*qsq35
*Oct 22
*/
#include <stdio.h>
#include <stdlib.h>
#include "set.h"

Set* create_set(char* file);

int main(int argc,char* argv[]){	
	if(argc!=4){
		printf("Usage: ./set <input file 1> <input file 2> <num>\n");
		return 0;
	}

	Set* first=create_set(argv[1]); //create
	Set* second=create_set(argv[2]);
	Set* intersection;
	
	printf("\nFirst set\n");  //print two lists
	print_list(first);
	printf("\nSecond set\n");
	print_list(second);
	
	intersection=set_intersection(first,second); //intersection
	printf("\nIntersection of the two sets\n");
	print_list(intersection);
	
	int data=atoi(argv[3]);  //intersection without the number input by user
	intersection=set_remove(intersection,data);
	printf("\nIntersection without %d\n",data);
	print_list(intersection);
	
	printf("\n--------Bonus--------\n");  //midpoint
	printf("The midpoint of the intersection is %d\n\n",getMiddle(intersection));
	
	free_list(first); //free
	free_list(second);
	free_list(intersection);
}
Set* create_set(char* file){
	FILE* fp=fopen(file,"r");
	Set* head=NULL;
	int data;
	while(1){
		fscanf(fp,"%d",&data);
		head=set_insert(head,data);
		if(feof(fp)){
			break;
		}
	}
	return head;
}
