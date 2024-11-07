#include "token.h"

struct Token *newList()
{
    struct Token *token = (struct Token *) malloc(sizeof(struct Token));
    token->data = (char *) "HEAD";
    token->type = STR;
    token->next = (struct Token *) malloc(sizeof(struct Token));
    token->next->data = (char *) "END";
    token->next->type = STR;
    return token;
}

// traverses a Token linked list until it reaches the "END" (end)
static struct Token *traverse(struct Token *head)
{
    if (head == NULL)
        return (struct Token *) -1;
    struct Token *current = head;
    while (current->next != NULL && strcmp(current->next->data, "END") != 0) current = current->next;
    return current;
}


// returns -1 for failure, 0 for success
// must have a head for the linked list
int append(struct Token *head, void *data, enum TokenType type)
{
    struct Token *current;
    if (head == NULL) return -1;
    current = traverse(head);
    current->next->next = (struct Token *) malloc(sizeof(struct Token));
    current->next->next->data = current->next->data;
    current->next->data = data;
    current->next->type = type;
    return 0;
}

void *top(struct Token *head)
{
    struct Token *current;
    if (head == NULL) return (void *) -1;
    current = traverse(head);
    return current->data;
}

int pop(struct Token *head)
{
    struct Token *current;
    if (head == NULL) return -1;
    current = traverse(head);
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