#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next,*back;
};
typedef struct node Node;

Node* insert_rear(Node *rear,int val)
{
  Node *newnode=(Node*)malloc(sizeof(Node));
  newnode->data=val;
  rear->next=newnode;
  newnode->next=NULL;
  newnode->back=rear;
  rear=newnode;
  return rear;
}
Node* insert_front(Node *front,int val)
{
  Node *newnode=(Node*)malloc(sizeof(Node));
  newnode->data=val;
  newnode->next=front;
  front->back=newnode;
  newnode->back=NULL;
  front=newnode;
  return front;
  
}
Node* delete_front(Node *front)
{
  if(front==NULL)
    printf("QUEUE is empty\n");
  else{
  front->next->back=NULL;
  Node *temp=front;
  front=front->next;
  free(temp);
  }
  return front;
}
Node* delete_tail(Node *rear)
{
  if(rear==NULL)
    printf("QUEUE is empty\n");
  else{
  rear->back->next=NULL;
  Node *temp=rear;
  rear=rear->back;
  free(temp);
  }
  return rear;
}

void del(Node **front,Node **rear,int val)
{
  if((*front)->data==val)
    {
      *front=delete_front(*front);
      if(*front==NULL)
	*rear=NULL;
    }
  else if((*rear)->data==val)
    {
      delete_tail(*rear);
    }
      
}
void ins(Node **front,Node **rear,int ref,int val)
{
  if(*front==NULL||*rear==NULL)
    {
      Node *newnode=(Node*)malloc(sizeof(Node));
      newnode->data=val;
      newnode->back=NULL;
      newnode->next=NULL;
      *front=newnode;
      *rear=newnode;
    }
  else if(ref==(*front)->data)
    {
      (*front)=insert_front(*front,val);
    }
  else if((*rear)->data==ref)
    {
      (*rear)=insert_rear(*rear,val);
    }
 
}
void display_front(Node *front)
{
  Node *temp;
  printf("The elements in the list are: ");
  for(temp=front;temp!=NULL;temp=temp->next)
    printf("%d ",temp->data);  
}

int main()
{
Node *front=NULL, *rear=NULL;
front=NULL;
rear=NULL;
int val,ref;
int c,c2;
do{
printf("\n1.Insert \n2.Delete\n3.Display\n4.Exit\n Enter your choice: ");
scanf("%d",&c);
switch(c)
  {
 case 1:
    printf("\n1.Insert head\n2.Insert tail\n Enter your choice:");
    scanf("%d",&c2);
    printf("Enter the value:");
    scanf("%d",&val);
    if(c2==1)
    {
       ins(&front,&rear,front==NULL?0:front->data,val);
    }
    else if(c2==2)
   {
      ins(&front,&rear,rear==NULL?0:rear->data,val);
   }
   break;
  case 2:
    printf("Delete \n1.Head\n2.Tail\n Enter your choice: ");
    scanf("%d",&c2);
    if(c2==1)
       del(&front,&rear,front->data);
    else if(c2==2)
       del(&front,&rear,rear->data);
    break;
 case 3:
    display_front(front);
       
    break;
 default:
    break;
}

}while(c!=4);

}
