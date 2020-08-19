#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* GetNewNode(int data){
    struct Node* NewNode = (struct Node*)malloc(sizeof(struct Node));
    NewNode->data = data;
    NewNode->left = NULL;
    NewNode->right = NULL;
    return NewNode;
}

struct Node* Insert(struct Node* root, int data){
    
    if(data <= root->data) {
        if(root->left == NULL){
            root->left = GetNewNode(data);
        } else{
            root->left = Insert(root->left, data);
        }
    } else {
        if(root->right == NULL){
            root->right = GetNewNode(data);
        } else{
            root->right = Insert(root->right, data);
        }
    }
    return root;
}

int Search(struct Node* root, int data){
    if(root == NULL){
        printf("Value [%d] not found.\n", data);
    }else if(root->data == data){
        printf("Value [%d] found.\n", data);
    }else if(data <= root->data){
        return Search(root->left, data);
    } else if(data >= root->data){
        return Search(root->right, data);
    }
}

void PreorderTraversal(struct Node* root){
    if(root == NULL) return;
    printf("[%d]", root->data);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

void InorderTraversal(struct Node* root){
    if(root == NULL) return;
    PreorderTraversal(root->left);
    printf("[%d]", root->data);
    PreorderTraversal(root->right);
}

void PostorderTraversal(struct Node* root){
    if(root == NULL) return;
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
    printf("[%d]", root->data);
}


int main(void){
    struct Node* root;
    root = GetNewNode(10);
    root = Insert(root, 15);
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 25);
    root = Insert(root, 14);
    root = Insert(root, 11);
    root = Insert(root, 9);

    Search(root, 1);
    Search(root, 23);

    PreorderTraversal(root);
    printf("\n");
    InorderTraversal(root);
    printf("\n");
    PostorderTraversal(root);
    printf("\n");

}