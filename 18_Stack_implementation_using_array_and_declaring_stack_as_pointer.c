// Stack implementation using array and declaring stack as pointer (  struct stack *s;)  in C (Explain in copy also)

#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=MD3mFgFwqBE&list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi&index=23&pp=iAQB
// https://www.youtube.com/watch?v=r2yHEW8HmBE&list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi&index=24&pp=iAQB
// see both video to understand you can see copy also
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *st)
{
    if (st->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *st)
{
    if (st->top == st->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc(s.size * sizeof(int));

    struct stack *s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // Pushing an element manually
    s->arr[0] = 7;
    s->top++;
    s->arr[1] = 5;
    s->top++;
    // Check if stack is empty
    if (isEmpty(s))
    {
        printf("The stack is empty");
    }
    else
    {
        printf("The stack is not empty");
    }
    if (isFull(s))
    {
        printf("The stack is full");
    }
    else
    {
        printf("\n");
        printf("The stack is not full");
    }
    return 0;
}
