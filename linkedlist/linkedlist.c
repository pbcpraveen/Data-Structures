#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
typedef struct node Node;
Node* insert(Node *head,int ref,int val)
{
  Node *temp;
  for(temp=head;temp!=NULL&&temp->data!=ref;temp=temp->next);
  Node *newnode=(Node*)malloc(sizeof(Node));
  newnode->data=val;
  newnode->next=temp->next;
  temp->next=newnode;
  return head;
}
Node* insert_tail(Node *tail,int val)
{
  Node *newnode=(Node*)malloc(sizeof(Node));
  newnode->data=val;
  tail->next=newnode;
  newnode->next=NULL;
  tail=newnode;
  return tail;
}
Node* insert_head(Node *head,int val)
{
  Node *newnode=(Node*)malloc(sizeof(Node));
  newnode->data=val;
  newnode->next=head;
  head=newnode;
  return head;
  
}
Node* delete_head(Node *head)
{
  Node *temp=head;
  head=head->next;
  free(temp);
  return head;
}

Node* delete(Node* head,int val)
{
  Node* temp;
  for(temp=head;temp!=NULL&&temp->next!=NULL&&temp->next->data!=val;temp=temp->next);
  Node* l=temp->next;
  temp->next=l->next;
  free(l);
  return head;
  
}
void del(Node **head,Node **tail,int val)
{
  if((*head)->data==val)
    *head=delete_head(*head);
  else
    *head= delete(*head,val);
}
void ins(Node **head,Node **tail,int ref,int val)
{
  if(*head==NULL)
    {
      Node *newnode=(Node*)malloc(sizeof(Node));
      newnode->data=val;
      newnode->next=NULL;
      *head=newnode;
      *tail=newnode;
    }
  else if(ref==101)
    {
      (*head)=insert_head(*head,val);
    }
  else if((*tail)->data==ref)
    {
      *tail=insert_tail(*tail,val);
    }
  else
    {
      *head=insert(*head,ref,val);
    }
}
void display(Node *head)
{
  Node *temp;
  printf("The elements in the list are: ");
  for(temp=head;temp!=NULL;temp=temp->next)
    printf("%d ",temp->data);  
}

int main()
{
  Node *head, *tail;
  head=NULL;
  tail=NULL;
  int n,val,ref;
  printf("Enter the number of elements in the list: ");
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      printf("Enter the element :");
      scanf("%d",&val);
      if(head==NULL)
	ins(&head,&tail,0,val);
      else
	ins(&head,&tail,(tail->data),val);
    }
  int c,c2;
  do{
    printf("\n1.Insert \n2.Delete\n3.Display\n4.Exit\n Enter your choice: ");
    scanf("%d",&c);
    switch(c)
      {
      case 1:
	printf("1.Insert at middle\n2.Insert head\n3.Insert tail\n Enter your choice:");
	scanf("%d",&c2);
	printf("Enter the value:");
	scanf("%d",&val);
	if(c2==1)
	  {
	    printf("Add after?: ");
	    scanf("%d",&ref);
	    ins(&head,&tail,ref,val);
	  }
	else if(c2==2)
	  {
	    ins(&head,&tail,101,val);
	  }
	else if(c2==3)
	  ins(&head,&tail,tail->data,val);
	break;
      case 2:
	printf("Enter the element to be deleted: ");
	scanf("%d",&val);
	del(&head,&tail,val);
	break;
      case 3:
	display(head);
	break;
      default:
	break;
      }
    
  }while(c!=4);
  
}
