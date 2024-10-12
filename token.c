#include "token.h"

struct Token *newList()
{
    struct Token *token = (struct Token *) malloc(sizeof(struct Token));
    token->str = "HEAD";
    return token;
}

// returns -1 for failure, 0 for success
// must have a head for the linked list
int append(struct Token *head, char str[])
{
    struct Token *current;
    if (head == NULL) return -1;
    current = head;
    while (current->next != NULL) current = current->next;
    current->next = (struct Token *) malloc(sizeof(struct Token));
    current->next->str = str;
    return 0;
}

int printList(struct Token *head)
{
    struct Token *current;
    if (head == NULL) return -1;
    current = head;
    while (current != NULL)
    {
        printf("%s\n", current->str);
        current = current->next;
    }
    return 0;
}