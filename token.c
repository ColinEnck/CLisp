#include "token.h"

struct Token *newList()
{
    struct Token *token = (struct Token *) malloc(sizeof(struct Token));
    token->data = "HEAD";
    token->type = STR;
    return token;
}

// returns -1 for failure, 0 for success
// must have a head for the linked list
int append(struct Token *head, void *data, enum TokenType type)
{
    struct Token *current;
    if (head == NULL) return -1;
    current = head;
    while (current->next != NULL) current = current->next;
    current->next = (struct Token *) malloc(sizeof(struct Token));
    current->next->data = data;
    current->next->type = type;
    return 0;
}

void *top(struct Token *head)
{
    struct Token *current;
    if (head == NULL) return (void *) -1;
    current = head;
    while (current->next != NULL) current = current->next;
    return current->data;
}

int pop(struct Token *head)
{
    struct Token *current;
    if (head == NULL) return -1;
    current = head;
    while (current->next != NULL) current = current->next;
    free(current);
}

// returns -1 for failure, 0 for success
int printList(struct Token *head)
{
    struct Token *current;
    if (head == NULL) return -1;
    current = head;
    while (current != NULL)
    {
        if (current->type == STR)
            printf("\"%s\"\n", (char *) current->data);
        else if (current->type == PTR)
            printList(current->data);
        current = current->next;
    }
    return 0;
}