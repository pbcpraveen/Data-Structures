#include<stdio.h>
int binarysearch(int [],int,int,int);
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
  int pos=binarysearch(a,0,n-1,k);
  if(pos==-1)
    printf("The element is not found.\n");
  else
    {
      printf("The element is found.\n");
      printf("Index:%d\n",pos);
      printf("Position:%d\n",pos+1);
    }
  return 0;
}
int binarysearch(int a[],int beg,int end,int k)
{
  if(beg>end)
    return -1;
  int mid=(beg+end)/2; 
  if(a[mid]==k)
    return mid;
  else if(a[mid]<k)
    return binarysearch(a,mid+1,end,k);
  else
    return binarysearch(a,beg,mid-1,k);
}
