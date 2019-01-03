#include  <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node Node;
void display(Node *head,int c)
{
    Node *temp;
    int i=0;
     for(temp=head->next;i<c;temp=temp->next)
        {
            if(temp==head)
                i++;
            printf("%d ",temp->data);
        }
}

void ins_after(Node *head,int after,int new_value)
{
    Node *temp=head;
    int flag=0;
    for(;temp->data!=after;)
      {
	temp=temp->next ;
	if(temp==head)
	  {
	    flag=1;
	    break;
	  }
      }
    if(flag==0){
    Node *newnode=(Node*)malloc(sizeof(Node));
    newnode->data=new_value;
    newnode->next=temp->next;
    temp->next=newnode;
    }
    
}
void delete(struct node * head,int ref)
{

   struct node * temp;
    for(temp=head->next;temp!=head;temp=temp->next)
    {
        if(temp->next->data==ref)
            temp->next=temp->next->next;
        
    }
}
int main(void)
{
    struct node *head,*temp,*prev;
    head=NULL;
    int i=0;
    int c=0;
    do
    {
        temp=(struct node *)malloc(sizeof(struct node));
	printf("Enter node value: ");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            prev=head;
            
        }
        else
        {
	  
            prev->next=temp;
            prev=temp;
        }
	printf("Do you want to continue: ");
	scanf("%d",&c);
    }while(c!=0);
    temp->next=head;
    display(head,1);
     printf("\n");
    int ins,ref;
    printf("Enter the element to be inserted: ");
    scanf("%d",&ins);
    printf("After what element: ");
    scanf("%d",&ref);
    ins_after(head,ref,ins);
    display(head,1);
     printf("\n");
    printf("Enter element to be deleted: ");
    scanf("%d",&ins);
    delete(head,ins);
    display(head,1);  
    return 0;
}
