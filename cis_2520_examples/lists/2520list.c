/* 
Note: Kremer's code is actually a bit different than this,
I have just rewritten it to match my coding style and w/
function prototypes at the top so I don't have to scroll too much

*/

#include <stdio.h>
#include <stdlib.h>

struct node {

    int value;
    struct node *next;

};

struct node *newNode(int value);
struct node *push(int value, struct node *list);
struct node *pop(struct node *list);
int peek(struct node *head);
struct node *copyNode(struct node *orig);
struct node *copyList(struct node *list);
void printNode(struct node *self);
void freeList(struct node *list);
void printList(struct node *list, int h2t, int t2h);

int main(int argc, char **argv) {
    
    struct node *list = NULL;
    struct node *list2;

    list = push(1, list);
    list = push(2, list);
    list = push(3, list);

    printList(list, 1, 0);

    list2 = copyList(list);

    printList(list2, 1, 0);

    freeList(list);
    freeList(list2);

    return 0;

}

struct node *newNode(int value) {

    struct node *ptr = malloc(sizeof(struct node));

    if (!ptr) {

        perror("malloc");
        exit(EXIT_FAILURE);

    }

    ptr->value = value;
    ptr->next = NULL;
    return ptr;

}

struct node *push(int value, struct node *list) {

    struct node *new = newNode(value);
    if (!new) return NULL;

    new->next = list;
    return new;

}

struct node *pop(struct node *list) {

    struct node *ptr = list->next;
    free(list);
    return ptr;

}

int peek(struct node *head) {

    return head->value;

}

struct node *copyNode(struct node *orig) {

    struct node *copy = newNode(orig->value);
    return copy;

}

struct node *copyList(struct node *list) {

    struct node *new_list = NULL;
    struct node **current_pos;

    /*
    current_pos = &new_list;
    while (list) {
        *current_pos = copyNode(list);
        current_pos = &((*current_pos)->next);
        list = list->next;
    }
    */

    for (current_pos = &new_list; list; current_pos = &((*current_pos)->next), list = list->next) {

        *current_pos = copyNode(list);
    
    }

    return new_list;

}

void printNode(struct node *self) {

    printf("Node address: %p\n", (void *)self);

    if (self) {

        printf("Node value: %d\n", self->value);
        printf("Next node: %p\n", (void *)self->next);

    }

    printf("\n");

}

void freeList(struct node *list) {

    if (list) {

        freeList(list->next);
        free(list);

    }

}

void printList(struct node *list, int h2t, int t2h) {

    if (h2t) printNode(list);

    if (list) printList(list->next, h2t, t2h);

    if (t2h) printNode(list);

}

