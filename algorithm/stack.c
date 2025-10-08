#include <stdio.h>
#include <stdlib.h>

struct stack {
    int *data;
    int top; // Empty = -1
    int size;
};

struct stack *init_stack(int size)
{
    struct stack *res = (struct stack *)malloc(sizeof(struct stack));
    if (!res) {
        printf("Stack Alloc Failed!\n");
        return NULL;
    }
    res->data = (int *)malloc(size * sizeof(int));
    if (!res->data) {
        printf("Data Alloc Failed!\n");
        return NULL;
    }
    res->top = -1;
    res->size = size;
    return res;
}

int is_full_stack(struct stack *s) 
{
    if (!s) return 1; // Illegal stack = Empty
    return s->top == s->size - 1;
}

int push(struct stack *s, int data)
{
    if (!s) return -1;
    if (is_full_stack(s)) {
        s->size *= 2;
        s->data = (int *)realloc(s->data, s->size * sizeof(int));
        if (!s->data) return -1;
    }
    s->data[++s->top] = data;   
    return 0;
}

int pop(struct stack *s)
{
    if (!s || s->top == -1) return -1;
    s->top--;
    return 0;
}

int peek(struct stack *s) 
{
    if (!s || s->top == -1) return -1;
    return s->data[s->top];
}

int free_stack(struct stack *s)
{
    if (!s || !s->data) return -1;
    free(s->data);
    free(s);
    return 0;
}

int main()
{
    // Do whatever you want with 'stack'
    return 0;
}