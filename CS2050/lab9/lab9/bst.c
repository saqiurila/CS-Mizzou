#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bst.h"

BST* insert(BST* tree,int data){
	BST* bst=(BST*)malloc(sizeof(BST));
	bst->data=data;
	bst->left=NULL;
	bst->right=NULL;

	if(tree==NULL){
		tree=bst;
	}else if(data<=tree->data){
		if(tree->left==NULL){
			tree->left=bst;
		}
		else{
			free(bst);
			tree->left=insert(tree->left,data);
		}
	}else if(data>tree->data){
		if(tree->right==NULL){
			tree->right=bst;
		}
		else{
			free(bst);
			tree->right=insert(tree->right,data);
		}
	}
	return tree;
}

BST* find(BST* tree,int data){
	if(tree==NULL){
		return NULL;
	}
	if(data<tree->data){
		return find(tree->left,data);
	}
	else if(data>tree->data){
		return find(tree->right,data);
	}
	else{
		return tree;
	}
}

BST* inorder(BST* tree){
	if(tree!=NULL){
		inorder(tree->left);
		printf("%d ",tree->data);
		inorder(tree->right);
	}
}

void print(BST* tree){
	if(tree==NULL){
		return;
	}
	else if(tree->left==NULL&&tree->right==NULL){
		free(tree);
	}
	else{
		print(tree->left);
		print(tree->right);
	}
}

BST* nearest(BST* tree,int data){
	int dif1=abs(tree->data-data);
	int dif2;
	BST* closest;
	BST* current=tree;
	while(current!=NULL){
		dif2=abs(current->data-data);
		if(dif1>dif2){
			dif1=dif2;
			closest=current;
		}
		if(data==current->data){
			return current;
		}
		else if(data<current->data){
			current=current->left;
			
		}
		else if(data>current->data){
			current=current->right;
		}
		
	}
	return closest;
}