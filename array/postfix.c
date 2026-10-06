#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct stack{
    struct Node* top;
} stack;

typedef struct queue {
    struct Node* front;
    struct Node* rear;
} queue;

// Fixed: Passed as a pointer so changes persist
void initialise(queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

void initialise_stack(stack *s){
    s->top=NULL;
}

void push(stack *s,int data){
    Node* temp=(Node* )malloc (sizeof(Node));
    if(temp==NULL){
        printf("Memory allocation failed");
        return;
    }
    temp->data=data;
    temp->next=NULL;
    if(s->top==NULL){
        s->top=temp;
        return;
    }
    temp->next=s->top;
    s->top=temp;
}

int pop(stack *s){
    
    if(s->top==NULL){
        printf("underflow");
        return -1;
    }
    int data=s->top->data;
    Node* temp=s->top;
    s->top=s->top->next;
    free(temp);
    return data;

}

// Fixed: Updated to correctly reference q->front and q->rear
void enqueue(queue *q, int data) {
    Node* temp = (Node*) malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation failed (Queue Overflow)\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    
    if (q->front == NULL && q->rear == NULL) {
        q->front = temp;
        q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(queue *q) {
    if (q->front == NULL) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }
    
    Node* temp = q->front;
    int dequeued_value = temp->data;
    
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp); 
    return dequeued_value;
}

void display(queue *q){
    Node* temp=q->front;
    if(q->front==NULL){
        printf("empty");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    free(temp);
}
//10 20 30 40 50

int main(void) {
    stack s;
    initialise_stack(&s);
    
    printf("--- Stack (Tail Insertion & Tail Pop) ---\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    printf("Popped from stack: %d\n", pop(&s)); // Outputs 30 (Last in, first out)
    printf("Popped from stack: %d\n", pop(&s)); // Outputs 20

    queue q;
    initialise_queue(&q);
    
    printf("\n--- Queue (Tail Insertion & Front Dequeue) ---\n");
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Dequeued from queue: %d\n", dequeue(&q)); // Outputs 10 (First in, first out)
    
    printf("Remaining Queue: ");
    display(&q); // Outputs 20 30
    return 0;
}
