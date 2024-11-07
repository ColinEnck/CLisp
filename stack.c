#include "stack.h"

struct Stack *newStack()
{
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    if (stack == NULL)
        return (struct Stack *) -1;
    else return stack;
}

