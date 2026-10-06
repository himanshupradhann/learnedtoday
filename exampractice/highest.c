#include <stdio.h>
#include <stdlib.h>
typedef struct hashing{
    int value;
    unsigned int frequency;
    struct hashing *next;
} hashing;

void createhash(hashing **head,int value){

    hashing * current =*head;
    while(current!=NULL){
        if(current->value==value){
            current->frequency++;
            return;
        }
        current=current->next;
    }

    hashing *temp=(hashing *) malloc (sizeof(hashing));

    temp->value=value;
    temp->frequency=1;
    temp->next=NULL;

    if(*head==NULL){
        *head=temp;
        return;
    }

    current=*head;
    while(current->next!=NULL){
        current=current->next;
    }

    current->next=temp;

}

int main (void){

   int arr[]={1,2,3,2,3,4,3,2,4,5,5,5,5};

   hashing *hash=NULL;


   for(int i=0;i<13;i++){
    createhash(&hash,arr[i]);
   }
  
    int frequency=0;
   hashing* tf=NULL;
   hashing *current=hash;
   while(current!=NULL){
    if(current->frequency>frequency){
        frequency=current->frequency;
        tf=current;
    }
    current=current->next;
   }

   printf("NUMBER :%d ",tf->value);
   printf("occurance :%d ",tf->frequency);
   return 0;
}