# Linked List Implementation — Explanation Template

---

## Struct Definition

```c

struct node {

    int value;
    struct node *next;

};

```

### Explanation
-Relatively unchanged from the standard implementation
-Holds an int value for each node, as well as a pointer to the next node

---

## newNode(int value)

```c

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

```

### Explanation
-Returns a pointer to a struct node
-Mallocs a ptr to a struct node, basic malloc check
-Sets value to the value and next to NULL, since it will always be the tail in this case
-Pretty much identical to the standard implementation
-We actually manually do this in an append function, but regardless the "return" is the same as its still a struct node ptr

---

## push(int value, struct node *list)

```c
struct node *push(int value, struct node *list) {
    struct node *new = newNode(value);
    if (!new)
        return NULL;

    new->next = list;
    return new;
}
```

### Explanation
-Returns a pointer to a node
-Sets the next of the node to list, which is NULL, which makes technical sense
-Works because list in main is a pointer to a node, so whenever we make list become the new node
-Therefore, it builds "from the tail"

---

## pop(struct node *list)

```c

struct node *pop(struct node *list) {
    struct node *ptr = list->next;
    free(list);
    return ptr;

}

```

### Explanation
-"Pops" a node, meaning we actually receive the full struct node back
-Stores address of next list node to ptr 
-Then, the list (or the head in this case) is free'd.
-Then returns the new pointer
-Take `2 -> 1 -> NULL` for example
-List = `2 ->` in this case, and so ptr becomes `1 -> NULL`
-`2 ->` is freed, and then the pointer to the head of the popped list is returned

---

## peek(struct node *head)

```c

int peek(struct node *head) {
    return head->value;
}

```

### Explanation
-Returns an integer which is just the value in the first node in the list. 
-Most commonly used in a stack, not a list, but functionaly correct
-Not actually used in the program, but could be used in print or peek

---

## 📋 copyNode(struct node *orig)

```c

struct node *copyNode(struct node *orig) {
    struct node *copy = newNode(orig->value);
    return copy;

}
```

### Explanation
-Returns a pointer to a node, which in this program is begins as the head node
-This is used in copy list to iteratively copy nodes and essentially create a new copy of list

---

## 📦 copyList(struct node *list)

```c

struct node *copyList(struct node *list) {
    struct node *new_list = NULL;
    struct node **current_pos;

    for (current_pos = &new_list; list;
         current_pos = &((*current_pos)->next), list = list->next) {
        *current_pos = copyNode(list);
    }

    return new_list;
}

```

### Explanation
-Returns a pointer to the first node in a newly copied list
-Initializes a null list to build on, new list
-Defines a pointer to a pointer to a node, current pos, which in this case is used as
-Setting the pointer to the address of new list
-In essence, current pos points to the address of new list, so we can change the values in new list without creating a copy
-Essentially, while there is a list, current pos is pointing to the address of the beginning of the new list, copies a node into the beginning value, sets itself to the address of its next value, and then increments the list

---

## 🖨 printNode(struct node *self)

```c
void printNode(struct node *self) {
    printf("Node address: %p\n", (void *)self);

    if (self) {
        printf("Node value: %d\n", self->value);
        printf("Next node: %p\n", (void *)self->next);
    }

    printf("\n");
}
```

### Explanation
-Takes a pointer to a node, and then
-Prints the actual pointer, or the address in memory it is pointing to
-If the node is not null, it also prints its value and the address it is pointing to (next node)

---

## 🧹 freeList(struct node *list)

```c

void freeList(struct node *list) {
    if (list) {
        freeList(list->next);
        free(list);
    }
}

```

### Explanation
-Takes the pointer to a list, in this program the head node
-If the list exists, i.e. not null, it recursively calls itself
-The base case is if the next node is null, which then
-Causes the nodes to start deleting themselves, starting from the tail

---

## 🪄 printList(struct node *list, int h2t, int t2h)

```c

void printList(struct node *list, int h2t, int t2h) {
    if (h2t)
        printNode(list);

    if (list)
        printList(list->next, h2t, t2h);

    if (t2h)
        printNode(list);
}

```

### Explanation
-If the user wants the list to be printed head to tail, set h2t to 1 -> causes a regular traversal through the list
-This is done because the node is printed before the recursive call, up until NULL
-t2h prints the next node before the node, causing it to be printed in reverse

---

## 🧠 main()

```c
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
```

### Explanation

-Creates pointer to a node list which starts empty (is the end of list)
-Creates pointer to a node list2
-Creates a list with 3 nodes, with the last being head, 3->2->1->NULL
-Prints list head to tail
-Copies list into list2
-Prints list2 head to tail
-Frees both lists

---

## 🧩 Summary
<!-- Add a short recap of what each function does and what you learned -->
