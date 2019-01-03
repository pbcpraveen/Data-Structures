#include<stdio.h>
void enqueue(int q[],int *front,int *rear,int k)
{
  if(*front==-1)
    {
      (*front)=(*rear)=0;
      q[(*rear)]=k;
    }
  else if(*rear+1==10)
  {
    printf("Queue is full\n");
  }
  else
    {
      (*rear)++;
	q[(*rear)]=k;
    }
  
}
void dequeue(int q[],int *front,int *rear)
{
  if(*front==-1)
    {
       printf("Queue is Empty\n");
    }
  else
    {
      (*front)++;
    }
  if(*front==(*rear)+1)
    *front=*rear=-1;
}
void display(int q[],int f,int r)
{
  if(r==-1)
    printf("No item to diplay.\n");
  else
    for(int i=f;i<=r;i++)
      {
	printf("%d ",q[i]);
      }
  printf("\n");
  
}

int main()
{
  int q[10];
  int front=-1,rear=-1;
  int c;
  
  do{
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    printf("Enter your choice: ");
    scanf("%d",&c);
    switch(c)
      {
      case 1:
	printf("Enter the valued to be Queued: ");
	int k;
	scanf("%d",&k);
	enqueue(q,&front,&rear,k);
	break;
      case 2:
	dequeue(q,&front,&rear);
	break;
      case 3:
	display(q,front,rear);
	break;
      case 4:
	printf("Exiting program\n");
	break;
      default:
	printf("Invalid choice.");
	break;
      }
  }while(c!=4);
}
