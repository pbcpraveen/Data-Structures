#include<stdio.h>
#include<stdlib.h>
void swap(int a[],int x,int y)
{
  int temp=a[x];
  a[x]=a[y];
  a[y]=temp;
}

int  insert(int a[],int n, int k)
{
  a[n]=k;
  for(int i=n;i>0;i=(i-1)/2)
    {
      if(a[(i-1)/2]<a[i])
	{
	  swap(a,(i-1)/2,i);  //(i-1)/2 is the parent index
	}
      else break;
    }
  return ++n;
}
void display(int a[], int n)
{
  for(int i=0;i<n;i++)
    {
      printf("%d ",a[i]); 
    }
  printf("\n");

}
int  delete(int a[],int n)
{
  a[0]=a[n-1];
  int i=0;
  while(i<(n-1)/2)
    {
      if(a[2*i+1]>a[i])
	{
	  if(a[2*i+2]<=a[2*i+1])
	    {
	      swap(a,2*i+1,i);  //2*i+1 is the left child index
	      i=2*i+1;
	    }
	  else if(a[2*i+2]>a[i])
	    {
	      swap(a,2*i+2,i);  //2*i+2 is the right  child index
	      i=i*2+2; 
	    }
	}
      else if(a[2*i+2]>a[i]&&a[2*i+1]<=a[2*i+2])
	{
	  if(a[2*i+1]<=a[2*i+2])
	    {
	      swap(a,2*i+2,i);  //2*i+2 is the right  child index
	      i=i*2+2;
	    }
	  else if(a[2*i+1]>a[i])
	    {
	      swap(a,2*i+1,i);  //2*i+2 is the right  child index
	      i=i*2+1; 
	    }
	}
      else break;
    }
  n--;
  return n;
}

void main()
{
  int a[100];
  int n,l;
  printf("Enter total number of elements:" );
  scanf("%d",&l);
  n=0;
  for(int i=0;i<l;i++)
    {
      printf("Enter the element to be inserted to the heap: ");
      int k;
      scanf("%d",&k);
      n=insert(a,n,k);
      display(a,n);
    }
  display(a,n);
  n=delete(a,n);
  printf("The root is deleted\n");
  display(a,n);
  
}
