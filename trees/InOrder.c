#include<stdio.h>
#include<stdlib.h>


struct node
{
int data;
struct node* left,*right;
};

struct node* newNode(int x)
{
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data=x;
	Node->left=NULL;
	Node->right=NULL;
	return Node;
}

void inOrder(struct node* tree)
{
	if(tree==NULL){return;}
	inOrder(tree->left);
	printf("%d\t",tree->data);
	inOrder(tree->right);
}

void postOrder(struct node* tree)
{
	if(tree==NULL){return;}
	postOrder(tree->left);
	postOrder(tree->right);
	printf("%d\t",tree->data);
}

void preOrder(struct node* tree)
{
	if(tree==NULL){return;}
	printf("%d\t",tree->data);
	preOrder(tree->left);
	preOrder(tree->right);
}
void main()
{
	struct node* root=newNode(12);
	root->left=newNode(67);
	root->right=newNode(-87);
	root->left->right=newNode(75);
	root->left->left=newNode(3);
	printf("INORDER TRAVERSAL:");
	inOrder(root);
	printf("\n");
	printf("PREORDER TRAVERSAL:");
	preOrder(root);
	printf("\n");
	printf("POSTORDER TRAVERSAL:");
	postOrder(root);
	printf("\n");
}


	

