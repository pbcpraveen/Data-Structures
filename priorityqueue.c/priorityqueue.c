#include <stdio.h> 
#include <stdlib.h> 
  
 
struct node { 
    int data; 
    int priority; 
    struct node* next;   
};
typedef struct node Node;  
Node* newNode(int d, int p) 
{ 
    Node *temp = (Node*)malloc(sizeof(Node));
    printf("HELLO");
    temp->data = d; 
    temp->priority = p; 
    temp->next = NULL;
    printf("HELLO");
    return temp; 
} 
void dequeue(Node** front) 
{ 
    Node* temp = *front; 
    (*front) = (*front)->next; 
    free(temp); 
} 
void enqueue(Node** front, int d, int p) 
{ 
    Node* start = (*front);  
    Node* temp = newNode(d, p);
    if(start==NULL)
      {
	*front=temp;
      }
    else if ((*front)->priority < p)
      {
        temp->next = *front; 
        (*front) = temp; 
      } 
    else { 
        while (start->next != NULL &&  start->next->priority >p)
	  { 
            start = start->next; 
	  } 
        temp->next = start->next; 
        start->next = temp; 
    } 
}
void display(Node* front)
{
  Node *temp;
  for(temp=front;temp!=NULL;temp=temp->next)
    {
      printf("%d-----%d\n",temp->data,temp->priority);
    }
}
 
int main() 
{
  Node *front=NULL;
  int val,priority;
  int c,c2;
  do{
    printf("\n1.Insert \n2.Delete\n3.Display\n4.Exit\n Enter your choice: ");
    scanf("%d",&c);
    switch(c)
      {
      case 1:
	printf("Enter the value: ");
	scanf("%d",&val);
	printf("Enter the priority: ");
	scanf("%d",&priority);
	if(front==NULL)
	  front=newNode(val, priority);
	else
	  enqueue(&front,val,priority);
	break;
      case 2:
	if(front==NULL)
	  printf("the queue is empty\n");
	else
	  {
	    dequeue(&front);
	    printf("Successfully Deleted\n");
	  }
	break;
      case 3:
	display(front);
	
	break;
      default:
	break;
      }
    
  }while(c!=4);
  
}

