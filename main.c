#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "token.h"
#include "mystring.h"

// parses the line of lisp code
struct Token *parse(char *line, int len);

int main(int argc, char const *argv[])
{
    char c, line[LINSIZ];
    struct Token *head = newList();
    int len;
    bzero(line, LINSIZ);

    for (;;)
    {
        // take a line of input
        for (len = 0; (c = getchar()) != '\n'; len++)
            line[len] = c;
        // split it into a list based on whitespace
        head = parse(line, len);
        printList(head);
    }

    free(head);
    return 0;
}

struct Token *parse(char *line, int len)
{
    // will hold the tokenized code
    struct Token *tokens = newList();
    // marks the current level in the linked list
    // (allows for lists inside lists)
    struct Token *level = tokens;
    // stack of the levels deep the linked lsit is
    struct Token *levels;
    // will hold the words of the line
    char **words;
    // number of spaces
    int numSpace = 0;
    char *newLine = addSpaceParens(line);
    int newLen = lenStr(newLine);
    // length of `words`
    int lenWords = countSpace(newLine);
    printf("\"%s\"\n", newLine);

    words = splitAtSpace(newLine);
    append(levels, (struct Token *) level, PTR);
    for (int i = 0; i < countSpace(newLine); i++)
        if (strcmp(words[i], "") != 0)
        {
            if (strcmp(words[i], "(") == 0)
            {
                append(levels, (struct Token*) newList(), PTR);
                level = top(levels);
            }
            else if (strcmp(words[i], ")") == 0)
            {
                pop(levels);
                level = top(levels);
            }
            else append(level, (char *) words[i], STR);
        }

    free(level);
    free(levels);
    free(words);
    free(newLine);
    return tokens;
}
