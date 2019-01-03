#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int coeff,deg;
  struct Node *next;
};

typedef struct Node node;

node* push(node *top,int coeff,int deg)
{
  if(coeff!=0)
    { 
      node *newnode=(node*)malloc(sizeof(node));
      newnode->coeff=coeff;
      newnode->deg=deg;
      if(top==NULL)
	{
	  top=newnode;
	  newnode->next=NULL;
	}
      else
	{
	  newnode->next=top;
	  top=newnode;
	}
    }
  return top;
}

void display(node *top,int max_deg)
{
  node *temp;
  int i=max_deg;
  for(temp=top;temp!=NULL;temp=temp->next,i--)
    {
      int t=temp->coeff>0?temp->coeff:-(temp->coeff);
      printf(" %dx^%d %c",t,temp->deg,temp->next==NULL?'\n':((temp->next->coeff>0)?'+':'-'));
    }
}
node* read_poly(node *poly,int max_degree)
{
  int i=0,coeff;
  while(i<=max_degree)
    {
      printf("Enter the coefficient for x^%d: ",i);
      scanf("%d",&coeff);
      if(coeff!=0)
	{
	  poly=push(poly,coeff,i);
	}
      i++;
    }
  return poly;
}
node* add(node *poly1,node* poly2,node* r,int n)
{
  if(n!=-1)
    {
      int a=0,b=0;
      if(poly1!=NULL&&poly1->deg==n)
	{
	  a=poly1->coeff;
	  poly1=poly1->next;
	}
      if(poly2!=NULL&&poly2->deg==n)
	{
	  b=poly2->coeff;
	  poly2=poly2->next;
	}
      int c=a+b;
      r=add(poly1,poly2,r,n-1);
      r=push(r,c,n);
    }
  return r;
}
int main()
{
  node *poly1=NULL,*poly2=NULL,*result=NULL;
  int ch,coeff,deg;
  int maxdegree;
  printf("Enter the maximum degree: ");
  scanf("%d",&maxdegree);
  poly1=read_poly(poly1,maxdegree);
  display(poly1,maxdegree);
  poly2=read_poly(poly2,maxdegree);
  display(poly2,maxdegree);
  result=add(poly1,poly2,result,maxdegree);
  display(result,maxdegree);
}
