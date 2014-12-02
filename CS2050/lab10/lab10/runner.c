/**
*FNU Saqiurila
*14227763
*qsq35
*Dec 19
*/
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc,char* argv[]){	
	if(argc!=3){
		printf("Usage: ./bst <input file> <num>\n");
		return 0;
	}
	//open file
	FILE* fp=fopen(argv[1],"r");
	if(fp==NULL){
		printf("Cannot open the file.");
		return 0;
	}
	//Read data from file into array
	int length;
	fscanf(fp,"%d",&length);
	int nums[length];
	int i;
	for(i=0;i<length;i++){
		fscanf(fp,"%d",&nums[i]);
	}
	fclose(fp);
	//Build tree
	BST* tree=build_balanced_tree(nums,0,length-1);
	printf("Tree--------------------------\n");
	print(tree);
	//delete
	int delete=atoi(argv[2]);
	printf("\nTree without %d----------------------\n",delete);
	tree=delete_node(tree,delete);	
	print(tree);
	//Reverse the tree
	printf("\nBonus---------------------------\n");
	tree=mirror(tree);
	print(tree);
	
	return 0;
}
