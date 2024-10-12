#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <stdio.h>
#include <stdlib.h>

struct Token
{
    char *str; // token
    struct Token *next; // next in linked list
};

struct Token *newList();

// returns -1 for failure, 0 for success
// must have a head for the linked list
int append(struct Token *head, char str[]);

int printList(struct Token *head);

#endif