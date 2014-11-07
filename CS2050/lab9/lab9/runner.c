#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc,char* argv[]){	
	if(argc!=4){
		printf("Usage: ./bst <input file> <number> <number>\n");
		return 0;
	}
	FILE* fp=fopen(argv[1],"r");
	if(fp==NULL){
		printf("Cannot open the file.\n");
		return 0;
	}
	//create
	BST* tree = NULL;
	int data;
	while(1){
		fscanf(fp,"%d",&data);
		tree=insert(tree,data);
		if(feof(fp)){
			break;
		}
	}
	//print
	inorder(tree);
	printf("\n");
	//search
	int number=atoi(argv[2]);
	BST* node=find(tree,number);
	if(node==NULL){
		printf("%d was not found\n",number);
	}
	else{
		printf("%d was found\n",node->data);
	}
	//find the closest number
	BST* closest=nearest(tree,atoi(argv[3]));
	printf("%d is the closest number to %d\n",closest->data,atoi(argv[3]));	
	//destroy
	print(tree);
	
	return 0;
}