#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int a[MAX];
int n=0;
void insert(int num){
    if(n<MAX){
        a[n]=num;
        n++;
    }
    else{
        printf("Array full\n");
    }
}
void makeheap(){
    int i;
    for(i=1;i<n;i++){
        int val=a[i];
        int j=i;
        int f=(j-1)/2;
        while(j>0&&a[f]<val){
            a[j]=a[f];
            j=f;
            f=(j-1)/2;
        }
        a[j]=val;
    }
}
void display(){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main()
    {
    int c,num;
    int n;
    printf("ENTER THE NUMBER OF ELEMENTS: ");
    scanf("%d",&n);
    int i=0;
    printf("Enter the elements: ");
    while(i<n){
        scanf("%d",&c);
        insert(c);
        i++;
    }
    display();
    makeheap();
    printf("\n");
    display();
    printf("\n");
}
