#include <stdio.h>
#include <stdlib.h>

struct Node {

    struct Node *next;
    int data;

};

void insertEnd(struct Node **head, int value); // may need to change head here, use double pointer
void printList(struct Node *head); // dont need to change head, so don't dereference head
void reverseList(struct Node **head); // same as insertEnd

int main(){

    struct Node *head = NULL; // begin with an empty list

    for (int i = 0; i < 5; i++){

        insertEnd(&head, i + 1);

    }

    printList(head);
    reverseList(&head);
    printList(head);

    return 0;

}

void insertEnd(struct Node **head, int value){

    struct Node* newNode = malloc(sizeof(struct Node));

    if(!newNode){

        perror("malloc failed @ insertEnd: newNode");
        return;

    }

    newNode->next = NULL; // if we're inserting at end, we know it is always the tail
    newNode->data = value;

    if(*head == NULL){

        *head = newNode; // if the list was empty this is the head
        return;

    }

    struct Node* temp = *head;

    while(temp->next != NULL){

        temp = temp->next;

    }

    temp->next = newNode;

}

void printList(struct Node *head){

    while(head != NULL){

        printf("%d -> ", head->data);
        head = head->next;

    }

    printf("NULL\n");

}

void reverseList(struct Node **head){

    struct Node* prev = NULL;
    struct Node* next = NULL;
    struct Node* curr = *head;

    while(curr != NULL){

        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;        

    }

    *head = prev;

} 
