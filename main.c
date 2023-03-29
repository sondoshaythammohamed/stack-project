#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    char data;
    struct Node *next;
} Node;
typedef struct
{
    Node *top;
} Stack;
Node *newNode (char x)
{
    Node *n = malloc(sizeof(Node));
    n->data = x;
    n->next = NULL;
    return n;
}
Stack * initialize ()
{
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}
void push (Stack *s , char x)
{
    Node *p = newNode(x);
    p->next = s->top;
    s->top = p;
}
char pop (Stack *s)
{
    if(s->top == NULL)
    {
        printf("Stack is Empty!");
        return;
    }
    Node *p = s->top;
    char data = p->data;
    s->top = p->next;
    free(p);
    return data;
}
char peak (Stack *s)
{

    if(s->top == NULL)
    {
        printf("Stack is Empty!");
        return;
    }
    else return s->top->data;
}
int isEmpty (Stack *s)
{
    if(s->top == NULL)
        return 1;
    else return 0;
}
void display (Stack *s)
{
    Stack *copy = initialize();
    while (!isEmpty(s))
    {
        int x = pop(s);
        printf(" %c ",x);
        push(copy,x);
    }
    while(!isEmpty(copy))
        push(s,pop(copy));
}
int main()
{
Stack *s = initialize();
push(s,'5');
push(s,'.');
push(s,'6');
push(s,'=');
push(s,'5');
push(s,'+');
push(s,'5');
push(s,'.');
push(s,'1');

display(s);
pop(s);
printf("%c",peak(s));
    return 0;
}
