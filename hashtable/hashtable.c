#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20
struct DataItem {
  int data;   
  int key;
};

struct DataItem* hashArray[SIZE]; 
struct DataItem* item;

int hashCode(int key) {
  int hashvalue=0;
  hashvalue=(hashvalue<<5)+key;
  return hashvalue % SIZE;//return key%size;
}

struct DataItem *search(int key)
{
  int hashIndex = hashCode(key);  
   while(hashArray[hashIndex] != NULL)
     {	
       if(hashArray[hashIndex]->key == key)
	 {
	   return hashArray[hashIndex];
	 }
       ++hashIndex;		
       hashIndex %= SIZE;
     }           
   return NULL;        
}

void insert(int key,int data) {
  
  struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
  item->data = data;  
  item->key = key;
  int hashIndex = hashCode(key);
  while(hashArray[hashIndex] != NULL) {
    ++hashIndex;
    hashIndex %= SIZE;
  }	
  hashArray[hashIndex] = item;
}

struct DataItem* delete(struct DataItem* item) {
  int key = item->key; 
  int hashIndex = hashCode(key);
  while(hashArray[hashIndex] != NULL)
    {	
      if(hashArray[hashIndex]->key == key) {
	struct DataItem* temp = hashArray[hashIndex]; 
	hashArray[hashIndex] = NULL;
	return temp;
      }
      ++hashIndex;
      hashIndex %= SIZE;
    }      
  
  return NULL;        
}

void display() {
  int i = 0;
  printf("KEY------>VALUE\n");
  for(i = 0; i<SIZE; i++) {
    
    if(hashArray[i] != NULL)
      printf(" %d ------> %d\n",hashArray[i]->key,hashArray[i]->data);
    else
       printf(" ~~ \n");
  }
  
  printf("\n");
}

int main() {
  int ch=1,k,v;
  int i=1;
  while(ch==1)
    {
      printf("Enter the key: ");
      scanf("%d",&k);
      printf("Enter the value for %d: ",k);
      scanf("%d",&v);
      insert(k,v);
      printf("Do you want to continue[1/0]: ");
      scanf("%d",&ch);
      i++;
      if(i==SIZE)
	{
	  printf("the hashtable is full\n" );
	  break;
	}
    }
  display();
  printf("Enter the key of the element to be searched for: ");
  scanf("%d",&k);
  item = search(k);
  if(item != NULL) {
    printf("Element found: %d\n", item->data);
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
