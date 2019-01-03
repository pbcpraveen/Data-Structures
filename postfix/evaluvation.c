#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void push(char stack[],char c,int* top)
{
  if((*top)!=40)
    stack[++(*top)]=c;
  else
    printf("\nStack full.\n");
}
char pop(char stack[],int* top)
{
  if(*top==-1)
    return '$';
  else
    return stack[(*top)--];
}
int precedence(char c)
{
  if(c=='^')
    return 4;
  else if(c=='/'||c=='*'||c=='%')
    return 3;
  else if(c=='+'||c=='-')
    return 2;
  else
    return 0;
}
int check(char scanned,char topmost)
{
  if(precedence(scanned)<=precedence(topmost))
    return 1;//to po from the stack
  else
    return 0;
}
int cal(int a, int b,char c)
{
  switch(c)
    {
    case '+':
      return a+b;
    case '-':
      return a-b;
    case '*':
      return a*b;
    case '/':
      return a/b;
    case '^':
      return (int)pow(a,b);
    default:
      return 0;
    }
}
void pushint(int stack[], int a,int* top)
{
  (*top)++;
  stack[(*top)]=a;
}
int popint(int stack[],int* top)
{
  return stack[(*top)--];
}

int main()
{
  char stack[40];
  char postfix[40];
  int count=0;
  int top=-1,i=0;
  char* c=(char*)malloc(sizeof(40));
  printf("Enter the string: ");
  scanf("%s",c);
  while(*(c+i)!='\0')
    {
      char p=*(c+i);
      if(p=='(')
	push(stack,p,&top);
      else if(p==')')
	{
	  while(stack[top]!='(')
	    {
	      char out=pop(stack,&top);
	      postfix[count++]=out;
	    }
	  p=pop(stack,&top);
	}
      else if(isdigit(p)!=0)
	{
	  postfix[count++]=p;
	  
	}
      else
	{
	  if(top==-1)
	    push(stack,p,&top);
	  else if(check(p,stack[top])==1)
	    {
	      while(check(p,stack[top])==1)
		{
		  char out=pop(stack,&top);
		  postfix[count++]=out;
		}
	      push(stack,p,&top); 
	    }
	  else
	    push(stack,p,&top);
	  
	}
      i++;
      
    }
   while(top>-1)
     postfix[count++]=stack[top--];
   postfix[count]='\0';
   printf("%s\n",postfix);
   int stack2[40],top2=-1;
   char *a2=postfix;//"53+4+2^";
   int i2=0;
   while(*a2!='\0')
     {
       if(isdigit(*a2)!=0)
	 {
	   int k2=(int)*a2-(int)'0';
	   pushint(stack2,k2,&top2);
	 }
       else
	 {
	   int p2=popint(stack2,&top2);
	   int q2=popint(stack2,&top2);
	   int c2= cal(q2,p2,*a2);
	   pushint(stack2,c2,&top2);
	 }
       a2++;
     }
   printf("result=%d\n",stack2[top2]);  
}
