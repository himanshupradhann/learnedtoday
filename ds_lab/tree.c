#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value){
    Node* newNode = (Node *) malloc (sizeof(Node));
    newNode->data=value;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

Node* insert(Node* root,int value){
    if(root==NULL){
        return createNode(value);
    }

    if(value < root->data){
        root->left=insert(root->left,value);
    }
    else if(value> root->data){
        root->right = insert(root->right,value);
    }
    return root;
}

void inorder(Node* root){

    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }

}

int main(void){
    
    Node* root =NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);

    return 0;
}