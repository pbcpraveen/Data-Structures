#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct Tree
{
  int data;
  struct Tree *right,*left;
};
void pre_order(struct Tree *root) 
 { 
   printf("%d ",root->data); 
   if(root->left!=NULL) 
     pre_order(root->left); 
   if(root->right!=NULL) 
       pre_order(root->right);
 }
void in_order(struct Tree *root) 
 { 
   if(root->left!=NULL) 
     in_order(root->left);
   printf("%d ",root->data); 
   if(root->right!=NULL) 
       in_order(root->right);
 }
void post_order(struct Tree *root) 
 { 
  
   if(root->left!=NULL) 
     post_order(root->left); 
   if(root->right!=NULL) 
      post_order(root->right);
    printf("%d ",root->data); 
 }
struct Tree *get_node()
{
  struct Tree *temp;
  temp=(struct Tree*)malloc(sizeof(struct Tree));
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
void insert(struct Tree *root,struct Tree *new)
{
  if(new->data<root->data)
    {
      if(root->left==NULL)
	root->left=new;
      else
	insert(root->left,new);
    }
  if(new->data>root->data)
    {
      if(root->right==NULL)
	root->right=new;
      else
	insert(root->right,new);
    }
}
struct Tree *search(struct Tree *root,int key,struct Tree **par)
{
  struct Tree *temp;
  temp=root;
  while(temp!=NULL)
    {
      if(temp->data==key)
	{
	  printf("Element is found:%d\n",temp->data);
	  return temp;
	}
      *par=temp;
      if(temp->data>key)
	temp=temp->left;
      else
	temp=temp->right;
    }
  return NULL;
}
int get_iop(struct Tree *root,int data)
{
  if(root->left!=NULL)
    get_iop(root->left,data);
  if(root->right!=NULL)
    get_iop(root->right,data);
  if(root->data!=data)
    {
      printf("%d ",root->data);
      return root->data;
    }
}
int delete(struct Tree *root,struct Tree *p,int data)
{
  if(root->left!=NULL)
    {
      delete(root->left,root,data);
    }
  if(root->right!=NULL)
    {
      delete(root->right,root,data);
    }
  if(root->data== data)
    {
      printf("%d ",root->data);
      if(p!=NULL)
	printf("%d\n",p->data);
      else
	printf("NULL \n");
    
  if(p->data>root->data)
    {
      if(root->left==NULL && root->right==NULL)
	{
	  p->left=NULL;
	}
      else if(root->left!=NULL && root->right==NULL)
	{
	  p->left=root->left;
	}
      else if(root->left==NULL && root->right!=NULL)
	{
	  p->left=root->right;
	}
      else if(root->left!=NULL && root->right!=NULL)
	{
	  int del;
	  del=get_iop(root->left,root->left->data);
	  printf("%d ",del);
	  delete(root->left,root,del);
	  root->data=del;
	}
    }
  else
    {
      if(root->left==NULL && root->right==NULL)
	p->right=NULL;
      else if(root->left!=NULL && root->right==NULL)
	p->right=root->left;
      else if(root->left==NULL && root->right!=NULL)
	p->right=root->right;
      else if(root->left!=NULL && root->right!=NULL)
	{
	  int del;
	  del=get_iop(root->left,root->left->data);
	  printf("%d ",del);
	  delete(root->left,root,del);
	  root->data=del;
	}
    }
    }
}
void del_root(struct Tree *root)
{
  int del;
  del=get_iop(root->left,root->left->data);
  printf("%d ",del);
  delete(root->left,root,del);
  root->data=del;
}
  
struct Tree *create(struct Tree *root,int data)
{
  struct Tree *temp;
  if(root==NULL)
    {
     temp=(struct Tree*)malloc(sizeof(struct Tree));
     temp->data=data;
     temp->left=NULL;
     temp->right=NULL;
     root=temp;
    }
  else
    {
      if(data<=root->data)
	{
	  if(root->left==NULL)
	    {
	      temp=(struct Tree*)malloc(sizeof(struct Tree));
              temp->data=data;
              temp->left=NULL;
              temp->right=NULL;
	      root->left=temp;
	    }
	  else
	    {
	      root=create(root->left,data);
	    }
	}
      else if(data>root->data)
	{
	  if(root->right==NULL)
	    {
	       temp=(struct Tree*)malloc(sizeof(struct Tree));
               temp->data=data;
               temp->left=NULL;
               temp->right=NULL;
	       root->right=temp;
	    }
	  else
	    {
	      root=create(root->right,data);
	    }
	}
      
    }
  return root;
}
int main(void)
{
  struct Tree *root=NULL,*rbu=NULL,*new;
  struct Tree *get_node(),*s,*par;
  int i,x,data;
  for(i=0;i<10;i++)
    {
      x=rand()%200;
      printf("%d ",x);
      root=create(rbu,x);
      if(i==0)
	rbu=root;
    }
  printf("\nThe preorder traversal of the generated tree is: ");
  printf("\n");
  pre_order(rbu);
  printf("\n");
  new=get_node();
  printf("Enter the new node to be inserted: ");
  scanf("%d",&new->data);
  insert(rbu,new);
  printf("Enter the element to be searched for: ");
  int k;
  scanf("%d",&k);
  s=search(rbu,k,&par);
  printf("The parent of %d is %d\n",s->data,par->data);
  printf("Enter the node to be deleted: ");
  scanf("%d",&k);
  delete(rbu,NULL,k);
  del_root(rbu);
  printf("\n");
  printf("The updated tree id: ");
  pre_order(rbu);
  printf("\n");

}
    
