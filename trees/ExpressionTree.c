#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int x)
{
	struct node* Node = (struct node*)malloc(sizeof(struct node));
	Node->data=x;
	Node->left=NULL;
	Node->right=NULL;
	return Node;
}

void postOrder(struct node* tree)
{
	if(tree==NULL){return;}
	postOrder(tree->left);
	postOrder(tree->right);
	printf("%c ",tree->data);
}


void main()
{
	int top=-1;
	struct node* stack[100];
	char str[]="74+3*4/23+%";
	printf("input:%s\n",str);
	for(int i=0;i<strlen(str);i++)
	{
		if(isdigit(str[i]))
		{	
			stack[++top]=newNode(str[i]);
		}
		else
		{
			struct node* temp;
			temp=newNode(str[i]);
			temp->right=stack[top--];
			temp->left=stack[top--];
			stack[++top]=temp;
		}
	}	
	printf("POSTORDER TRAVERSAL OF THE EXPRESSION TREE IS :");
	postOrder(stack[top]);
	printf("\n");
}

