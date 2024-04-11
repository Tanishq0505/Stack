// Multiple brackets of different types  Checking Using Stack in C Language (Explain in copy also) 

// https://www.youtube.com/watch?v=QURbEGE-F_Y&list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi&index=34&t=462s&pp=iAQB 
// see video you can see copy also 

#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}

int match(char a, char b)
{
    // this function  is to match the opening bracket present in stack with the  closing bracket found in
    // expression
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    // . If the match function returns 1, our pop operation is successful, and we can
    // continue checking further characters; else, if it returns 0, end the program here itself and return 0
    // to the main.
    return 0;
}

int parenthesisMatch(char *exp)
{
    // Create and initialize the stack
    struct stack *sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);           //-->we store our popped opening bracket from stack
            if (!match(popped_ch, exp[i])) //-->we compare using match function
            // this function  is to match the opening bracket present in stack with the  closing bracket found in
            // expression
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
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
    char *exp = "[4-6]((8){(9-8)})";

    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced");
    }
    else
    {
        printf("The parenthesis is not balanced");
    }
    return 0;
}
