#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

struct List{
  int val;
  int key;
  struct List *next;
  
};

typedef struct List list;

list* hashArray[SIZE];
list* item;

int hashCode(int key) {
  int hashvalue=key*key;
  return hashvalue % SIZE;
}
//Inserting
list* insertn(list* l,int key,int val)
{
  list* n=(list*)malloc(sizeof(list));
  n->key=key;
  n->val=val;
  n->next=NULL;
  if(l==NULL)
    {
      l=n;
    }
  else
    {
      list* temp=l;
      for(;temp->next!=NULL;temp=temp->next);
      temp->next=n; 
    }
  return l;
}
void insert(int key,int data) {
  
  struct List *item = (struct List*) malloc(sizeof(struct List));
  item->val = data;  
  item->key = key;
  int hashIndex = hashCode(key);	
  hashArray[hashIndex]=insertn(hashArray[hashIndex],key,data);
}

//Searching
list* searchn(list* l,int key)
{
  for(list* temp=l;temp!=NULL;temp=temp->next)
    {
      if(temp->key==key)
	return temp;
    }
  return NULL;
}
list* search(int key)
{
  int hashIndex = hashCode(key);  
  return searchn(hashArray[hashIndex],key);      
         
}

list* deleten(list* l,int key)
{
  list* temp=l;
  if(temp!=NULL){
    if(temp->next==NULL&&temp->key==key){
      l=NULL;
    }
    else{
      for(;temp->next!=NULL&&temp->next->key!=key;temp=temp->next);
      if(temp->next!=NULL)
	{
	  list* k= temp->next;
	  temp->next=k->next;
	  free(k);
	}
    }
  }
  return l;
}
void delete(struct List* item) {
  int key = item->key; 
  int hashIndex = hashCode(key);
  hashArray[hashIndex]=deleten(hashArray[hashIndex],item->key);        
}
// display
void displayn(list* l)
{
  for(list* temp=l;temp!=NULL;temp=temp->next)
    {
      printf("(%d,%d)--->",temp->key,temp->val);
    }
  printf("NULL\n");
}

void display() {
  int i = 0;
  printf("KEY------>VALUE\n");
  for(i = 0; i<SIZE; i++) {
    
    if(hashArray[i] != NULL)
      displayn(hashArray[i]);
    else
       printf(" ~~ \n");
  }
  
  printf("\n");
}
int main() {
  int ch=1,k,v;
  while(ch==1)
    {
      printf("Enter the key: ");
      scanf("%d",&k);
      printf("Enter the value for %d: ",k);
      scanf("%d",&v);
      insert(k,v);
      printf("Do you want to continue[1/0]: ");
      scanf("%d",&ch);
    }
  display();
  printf("Enter the key of the element to be searched for: ");
  scanf("%d",&k);
  item = search(k);
  if(item!=NULL) {
    printf("Element found: %d\n",item->val);
  } else {
    printf("Element not found\n");
  }
  printf("Enter the key of the element to be deleted: ");
  scanf("%d",&k);
  if((item = search(k))==NULL)
    printf("There is no such element.\n");
  else
    {
      delete(item);
      printf("The element is succesfully deleted.\n");
      display();
    }
}
