#include<stdio.h>
#include<stdlib.h>
struct node
{
  int a;
  struct node* next;
};
typedef struct node Node;
int main()
{
  Node *list=NULL;
  int ch;
  int val,num;
  do
    {
      printf("Enter node value: ");
      scanf("%d",&val);
      Node* n=(Node*)malloc(sizeof(Node));
      n->next=list;
      n->a=val;
      list=n;
      printf("Do you wnat to continue[1/0]:");
      scanf("%d",&ch);
    }while(ch==1);
  printf("linked list is: ");
  Node *k=list;
  while(k!=NULL)
    {
      printf("%d ",k->a);
      k=k->next;
    }
  printf("\nenter the element to be found: ");
  scanf("%d",&num);
  k=list;
  while(k!=NULL)
    {
      if(k->a==num)
	{
	  printf("The element is found in the list.\n");
	  break;
	}
      k=k->next;
    }
  if(k==NULL)
    printf("the element is not found");
}
