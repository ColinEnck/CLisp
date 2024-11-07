#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// type of data stored in a token:
// a string or a pointer to another list
enum TokenType
{
    STR,
    PTR
};

struct Token
{
    void *data; // token
    enum TokenType type; // type of data (string or pointer to another list)
    struct Token *next; // next in linked list
};

struct Token *newList();

// returns -1 for failure, 0 for success
// must have a head for the linked list
int append(struct Token *head, void *data, enum TokenType type);

// returns last entry in linked list
void *top(struct Token *head);

// returns -1 for failure, 0 for success
// removes last entry in linked list
int pop(struct Token *head);

int printList(struct Token *head);

#endif