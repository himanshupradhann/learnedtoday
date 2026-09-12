#ifndef HASH
#define HASH


typedef struct hashing{
    int value;
    unsigned int frequency;
    struct hashing *next;
} hashing;

void createhash(struct hashing **head, int value);
void print(struct hashing* head);
void addhash(int arr[],struct hashing **head,int max);

#endif
