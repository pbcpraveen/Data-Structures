#include<stdio.h>
int LinearSearch(int [],int,int);
int main()
{
  int a[100],n,k;
  printf("Enter the number of elements:");
  scanf("%d",&n);
  printf("Enter the elements of the array: ");
  for(int i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  printf("Enter the element to be found:");
  scanf("%d",&k);
  int pos=LinearSearch(a,n,k);
  if(pos==-1)
    printf("The element is not found.");
  else
    {
      printf("The element is found.\n");
      printf("Index:%d\n",pos);
      printf("Position:%d",pos+1);
    }
  return 0;
}
int LinearSearch(int a[],int n,int k)
{
  for(int i=0;i<n;i++)
    {
      if(a[i]==k)
	return i;
    }
  return -1;
}
int binarysearch(int a[],int beg,int end,int k)
{
  if(beg>end)
    return -1;
  int mid=(beg+end)/2; 
  if(a[mid]==k)
    return mid;
  else if(a[mid]>k)
    return binarysearch(a,mid+1,end,k);
  else
    return binarysearch(a,beg,mid0-1,k);
}
