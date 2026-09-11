#ifndef HASH
#define HASH

struct hashing;

void createhash(struct hashing **head, int value);
void print(struct hashing* head);
void addhash(int arr[],struct hashing **head,int max);

#endif
