#include <stdio.h>
#include <stdlib.h>

struct Node {

    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node *n){

    if(n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

struct Node* getNewNode(int data){

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    
    return newNode;
}

struct Node* rightRotate(struct Node* n){
    
    struct Node* x = n->left;
    struct Node* y = x->right;

    x->right = n;
    n->left = y;

    n->height = max(height(n->left), height(n->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
    return x;
}

struct Node* leftRotate(struct Node* x){
    
    struct Node* y = x->right;
    struct Node* n = y->left;

    y->left = x;
    x->right = n;

    x->height = max(height(x->left), height(x->right))+1; 
    y->height = max(height(y->left), height(y->right))+1; 

    return y;
}

int getBalance(struct Node* n){
    
    if(n == NULL){
        return 0; 

    } else{
        return height(n->left) - height(n->right);
    }
}

struct Node* insert(struct Node* root, int data){

    if(root == NULL){
        return getNewNode(data);
    }
    if(data <= root->data) {
        root->left = insert(root->left, data);
    } 
    else {
        root->right = insert(root->right, data);
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    //4 cases of unbalanced tree:

    if(balance > 1 && data < root->left->data) { // left left case
        return rightRotate(root);
    }

    if(balance > 1 && data > root->left->data) { // left right case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && data > root->right->data) { // right right case
        return leftRotate(root);
    }

    if(balance < -1 && data < root->right->data) { // right left case
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}

int search(struct Node* root, int data){
    
    if(root == NULL){
        printf(" Value [%d] not found.\n", data);
    }
    else if(root->data == data){
        printf(" Value [%d] found.\n", data);
    }
    else if(data <= root->data){
        return search(root->left, data);
    }
    else if(data >= root->data){
        return search(root->right, data);
    }
}

void preorderTraversal(struct Node* root){

    if(root == NULL) return;
    printf("[%d]", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(struct Node* root){

    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("[%d]", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct Node* root){
    
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("[%d]", root->data);
}

void LevelOrderTraversal(struct Node* root, int level){

    if(root == NULL){
        return;
    }
    if(level == 0){
        printf("[%d]", root->data);
    } 
    else{ 
        LevelOrderTraversal(root->left, level-1);
        LevelOrderTraversal(root->right, level-1);
    }
}

void printLevelOrder(struct Node* root){
    int h = height(root);
    for(int i = 0; i < h; i++){
        LevelOrderTraversal(root, i);
    }
}

struct Node* findMin(struct Node* root){
    struct Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


struct Node* delete(struct Node* root, int data){

    if(root == NULL){
        return root;
    }
    if(data < root->data) {
        root->left = delete(root->left, data);
    } 
    else if(data > root->data){
        root->right = delete(root->right, data);
    }
    else{
        if( (root->left == NULL) || (root->right == NULL) ){
            struct Node* temp = root->left ? root->left : root->right;
            
            if(temp == NULL){
                temp = root;
                root = NULL;
            } else{
                *root = *temp;
                free(temp);
            }
        }
        else{
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && (getBalance(root->left) >= 0)) { // left left case
        return rightRotate(root);
    }

    if(balance > 1 && (getBalance(root->left) < 0)) { // left right case
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && (getBalance(root->right) <= 0)) { // right right case
        return leftRotate(root);
    }

    if(balance < -1 && (getBalance(root->right) > 0)) { // right left case
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    
    return root;
}


int main(void){

    struct Node* root;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 7);

    search(root, 1);
    search(root, 23);

    printf("\n Preorder: ");
    preorderTraversal(root);

    printf("\n Inorder: ");
    inorderTraversal(root);

    printf("\n Postorder: ");
    postorderTraversal(root);

    printf("\n Levelorder: ");
    printLevelOrder(root);

    root = delete(root, 7);

    printf("\n Levelorder: ");
    printLevelOrder(root);

    root = delete(root, 6);

    printf("\n Levelorder: ");
    printLevelOrder(root);

    root = delete(root, 5);

    printf("\n Levelorder: ");
    printLevelOrder(root);

    return 0;

}