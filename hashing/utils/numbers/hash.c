#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

void createhash(hashing **head,void *value){
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

void print(hashing* head) {
    hashing* current = head;
    while (current != NULL) { 
        printf("%d %d\n", current->value, current->frequency);
        current = current->next;
    }
}

void addhash(int arr[],hashing **head,int max){
    for(int i=0;i<max;i++){
        createhash(head,arr[i]);
    }
}