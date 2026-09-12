#include <stdio.h>



//
#include "../hashing/utils/characters/hash.h"
#define max 5

//defining struct
typedef struct hashing{
    char KEY;
    unsigned int frequency;
    struct hashing *next;
} hashing;

//custom print statement
void printt(hashing* head) {
    hashing* current = head;
    while (current != NULL) { 
        printf("KEY: %c -> %d\n", current->KEY, current->frequency);
        current = current->next;
    }
}

void arrange(hashing *head){

}

//main function
int main() {
    struct hashing *tail = NULL; 
    int arrr[max]={'a','b','c','d','e'};
    addhash(arrr,&tail,max);
    printt(tail);
    return 0;
}