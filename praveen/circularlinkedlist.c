#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
typedef struct node Node;

Node* insert(Node *head,int val)
{
  
  Node *newnode=(Node*)malloc(sizeof(Node));
  newnode->data=val;
  if(head==NULL)
    {
       newnode->next=newnode;
      head=newnode;
     
    }
  else
    {
      Node* temp;
      for( temp=head;temp->next!=head;temp=temp->next);
      newnode->next=temp->next;
      temp->next=newnode;
    }
  return head;
  
}

Node* delete(Node* head,int val)
{
  Node* temp;
  if(head==NULL)
    printf("QUEUE IS EMPTY.\n");
  else if(head->data==val&&head->next==head)
    head=NULL;
  else
    {
      for(temp=head;temp->next->data!=val&&temp->next!=head;temp=temp->next);
      temp->next=temp->next->next;
      head=temp;
      
    }
  return head;
}

void display(Node* head,int c)
{
  int i=-1;
  if(head==NULL)
    printf("THE QUEUE IS EMPTY.\n");
  else
    {
      for(Node* temp=head;c>i;temp=temp->next)
	{
	  if(temp==head)
	    i++;
	  if(c>i)
	    printf("%d ",temp->data);
	  
	}
      printf("\n");
    }
}
int main()
{
  Node *head;
  head=NULL;
  int n,val;
  int c,c2;
  do{
    printf("\n1.Insert\t2.Delete\t3.Display\t4.Exit\n Enter your choice: ");
    scanf("%d",&c);
    switch(c)
      {
      case 1:
	printf("Enter the value:");
	scanf("%d",&val);
	head=insert(head,val);
	break;
      case 2:
	printf("Enter the element to be deleted: ");
	scanf("%d",&val);
	delete(head,val);
	break;
      case 3:
	printf("how much time to display: ");
	scanf("%d",&c2);
	display(head,c2);
	break;
      default:
	break;
      }
    
  }while(c!=4);
  
}

