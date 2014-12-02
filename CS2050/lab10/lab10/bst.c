#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

BST* build_balanced_tree(int a[], int low, int high){
	int mid=(low+high)/2;
	//base case
	if(low>high){
		return NULL;
	}
	//new node
	BST* tree=malloc(sizeof(BST));
	tree->data=a[mid];
	tree->left=build_balanced_tree(a,low,mid-1);
	tree->right=build_balanced_tree(a,mid+1,high);
	
	return tree;
}

BST* delete_node(BST* tree,int data){
	//nothing to delete
	if(tree==NULL){
		return tree;
	}
	//go left
	else if(data<tree->data){
		tree->left=delete_node(tree->left,data);
	}
	//go right
	else if(data>tree->data){
		tree->right=delete_node(tree->right,data);
	}
	//find it
	else{
		//at most only have child on the right
		if(tree->left==NULL){
			BST* temp=tree->right;
			free(tree);
			return temp;
		}
		//Only have child on the left
		else if(tree->right==NULL){
			BST* temp=tree->left;
			free(tree);
			return temp;
		}
		//Have two children
		else{
			//Find the minimum node on the right side of the tree
			BST* mini=min(tree->right);
			//swap tree node with minimum node
			int temp=tree->data;
			tree->data=mini->data;
			mini->data=temp;
			//delete data from the right side
			tree->right=delete_node(tree->right,data);
			return tree;
		}
	}
	return tree;
}

BST* min(BST* root){
	BST* current=root;
	//Go left to find the minimum node
	while(current->left!=NULL){		
		current=current->left;
	}
	return current;
}

void padding(char ch, int n) {
    int i;

    for (i = 0; i < n; ++i) {
        putchar(ch);
    }
}

void structure(BST* root, int level) {
    int i;

    if (root == NULL) {
        padding('\t', level);
        puts("~");
    } else {
        structure(root->right, level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        structure(root->left, level+1);
    }
}

void print(BST* root){
	structure(root,0);
}

BST* mirror(BST* root){
	if(root==NULL){
		return NULL;
	}else if(root->left==NULL&&root->right==NULL){
		return root;
	}
	//Swap left child and right child
	BST* temp=root->left;
	root->left=root->right;
	root->right=temp;
	
	root->left=mirror(root->left);
	root->right=mirror(root->right);
	
	return root;
}