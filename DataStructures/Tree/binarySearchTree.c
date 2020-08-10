#include <stdio.h>
#include <stdlib.h>

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

int FindHeight(struct Node* root){
    if(root = NULL){
        return -1;
    } else{
        printf("Entrou aqui");
        int left = FindHeight(root->left );
        printf("left: %d", left);
        //return left->data;
      //  int right = FindHeight(root->right);
    }//
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
        return 0;
    }else if(root->data == data){
        return 1;
    }else if(data <= root->data){
        return Search(root->left, data);
    } else if(data >= root->data){
        return Search(root->right, data);
    }
}

//void delete(){
//
//}

int main(void){
    struct Node* root;
    root = GetNewNode(10);
    root = Insert(root, 15);
    root = Insert(root, 5);
    root = Insert(root, 1);
    root = Insert(root, 25);
    root = Insert(root, 32);
    root = Insert(root, 11);

    int n;
    printf("Enter number: \n");
    scanf("%d",&n);
    if(Search(root, n) == 1) {
        printf("Value found.\n");
    } else{
        printf("Value not found.\n");
    }

}