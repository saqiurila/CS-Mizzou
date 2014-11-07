/**
*FNU Saqiurila
*14227763
*qsq35
*Nov 5
*/
#ifndef BST_H_
#define BST_H_

typedef struct node_{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

BST* insert(BST *tree,int data);
BST* find(BST *tree,int data);
BST* inorder(BST *tree);
void print(BST *tree);
BST* nearest(BST* tree,int data);

#endif