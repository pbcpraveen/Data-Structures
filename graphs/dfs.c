#include  <stdio.h>
#include<stdlib.h>
#define size 10
int g[size][size];
int v[size];  
int flag=0; 
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
void dfs(int i,int k)
{
    v[i]=1;
    int j;
    if(k==i)
    {	
	printf(" %d ",i+1);
        flag=1;
	return;
    }
    for(j=0;j<size;j++)
    {
        if(v[j]==0 && g[i][j]==1)
            dfs(j,k);
            if(flag)
              {
                printf("%d ",i+1);
                return;
              }
            
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
    printf("\n");
    printf("The dfs path between 4-8 is: "); 
    dfs(7,3);
    printf("\n");
    return 0;
}
