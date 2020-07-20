#include <stdio.h>
#include <stdlib.h>

// First we create a structure to represent the node type that has a data and a link to next node
struct Node {
    int data;
    struct Node *link;
};

// We need to store the head node - it points to null while it is and empty linked list
struct Node *headNode;

// this function insert elements in the list

void insertElementBeggining(int x){
    // temp is a variable that stores the adress memory which malloc() takes
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x; // temp node receive x as value
    temp->link = NULL; // temp node receive null as link
    if(headNode != NULL){ // if headNode is linked to an element
        temp->link = headNode; // temp node link is now headnode
        headNode = temp; // and the headnode is now temp
    }
}

void printList(){
    insertElementBeggining(10);
    printf("headnode: %d", headNode->data);
}

int main(){
    printList();
}