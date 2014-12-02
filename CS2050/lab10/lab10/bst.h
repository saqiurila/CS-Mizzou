/**
*FNU Saqiurila
*14227763
*qsq35
*Dec 19
*/
#ifndef BST_H_
#define BST_H_

typedef struct node_{
	int data;
	struct node_* left;
	struct node_* right;
}BST;

BST* build_balanced_tree(int a[], int low, int high);
BST* delete_node(BST* tree,int data);
BST* min(BST* root);
void padding(char ch,int n);
void structure(BST* root,int level);
void print(BST* root);
BST* mirror(BST* root);

#endif