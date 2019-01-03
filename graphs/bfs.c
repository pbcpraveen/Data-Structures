#include<stdio.h>
#include<stdlib.h>
#define size 5
int v[size];
int g[size][size];
int front=-1,rear=-1,q[100];
void display()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf(" %d",g[i][j]);
        }
        printf("\n");
    }
}

void enq(int val)
{
  if(front==-1)front++;
  rear++;
  q[rear]=val;
}

int deq()
{
  if(front ==-1 && rear==-1)
    {return -1;}
  else if(front == rear)
    {
      int val = q[front];
      front=-1;
      rear=-1;
      return val;
    }
  else
    {
      int val = q[front];
      front++;
      return val;
    }
}

void bfs(int i,int k)
{
  if(v[i]==0)
    {
      v[i]=1;
      int j;
      if(k==i)
	{
	  printf("%d ",i);
       	  return;
	}
      for(j=0;j<size;j++)
	{
	  if(v[j]==0 && g[i][j]==1)
	    enq(j);
	}
    }
  int val = deq();
  if(val!=-1)
    {
      bfs(val,k);
      printf("%d ",i);
    }
}

int main(void)
{
    int i,j;
    for(i=0;i<size;i++) 
        v[i]=0;
    for(i=0;i<size;i++)
    {
        for(j=i;j<size;j++)
        {
            if(i==j)
                g[i][j]=0;
            else
                g[i][j]=rand()%2;
                g[j][i]=g[i][j];
        }
    }
    display();
    printf("traversal:\n");
    printf("The path between 0-7 is: ");
    bfs(3,0);
    printf("\n");
}
