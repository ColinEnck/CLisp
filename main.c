#include <stdio.h>
#include <stdlib.h>
#include "token.h"

int main(int argc, char const *argv[])
{
    FILE *in;
    char buf[64];
    struct Token *head = newList();
    struct Token *current;
    if (argc != 2)
    {
        printf("USAGE: %s [INPUT FILENAME]\n", argv[0]);
        return 0;
    }
    in = fopen(argv[1], "r");
    fread(buf, 1, 64, in);

    append(head, "Hello world");
    append(head, "Hi again!");
    printList(head);

    return 0;
}