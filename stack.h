#ifndef __STACK_H__
#define __STACK_H__
#include "token.h"
#include <stdlib.h>

struct Stack
{
    struct Token *data;
    struct Stack *next;
};

// creates new stack
struct Stack *newStack();

// pushes new token list
void push(struct Token *data);

// pops top of stack, returns topmost token list
struct Token *pop(struct Stack *stack);

#endif