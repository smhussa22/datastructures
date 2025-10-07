#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct Stack {

    int top, capacity;
    int array[MAX];

};

void push(struct Stack* s, int value);
int peek(struct Stack* s);
int pop (struct Stack* s);
void printStack(struct Stack* s);

int main(){

    struct Stack s;
    s.top = -1; // stack's empty
    s.capacity = 5;

    for(int i = 0; i < 3; i++){

        push(&s, (i + 1) * 10);

    }

    printf("Peeked at stack\n: %d", peek(&s));
    printStack(&s);
    pop(&s);
    printf("Peeked at stack\n: %d", peek(&s));
    printStack(&s);

    return 0;

}

void push(struct Stack* s, int value){

    if(s->top == s->capacity - 1) return;
    s->top++;
    s->array[s->top] = value;

}

int peek(struct Stack* s){

    if(s->top == -1) return -1;
    int peeked = s->array[s->top];
    return peeked;

}

int pop (struct Stack* s){

    if(s->top == -1) return -1;
    int popped = s->array[s->top];
    s->top--;
    return popped;

}

void printStack(struct Stack* s){

    if(s->top == -1) return;

    printf("Stack : \n");

    for(int i = s->top; i >= 0; i--){

        printf("%d\n", s->array[i]);

    }

    printf("\n");

}