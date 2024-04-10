// How to implement stack using Linked list in c++ gfg 
// https://www.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

#include <iostream>
#include <stack>
// https://youtu.be/0BTDISr-8xU?list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi
// see  this video to understand you can see copy also
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *push(struct Node *top, int x)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Stack Overflow\n");
    }
    else
    {

        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
int peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty!");
        return -1;
        printf("\n");
    }
    else
    {
        return top->data;
    }
}

struct Node *pop(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        printf("Popped element is %d\n", x);
        free(n);
        return top;
    }
}

int main()
{
    struct Node *top = NULL;
    top = push(top, 78);
    top = push(top, 7);
    top = push(top, 8);
    linkedListTraversal(top);
    printf("peek=%d\n", peek(top));
    top = pop(top);
    printf("peek=%d\n", peek(top));

    linkedListTraversal(top);
    return 0;
}
