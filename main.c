#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "token.h"
#include "mystring.h"
#include "stack.h"

// tokenize the line
struct Token *retWords(char *line, int len);

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
        head = retWords(line, len);
        printList(head);
    }

    free(head);
    return 0;
}

struct Token *retWords(char *line, int len)
{
    // will hold the tokenized code
    struct Token *tokens = newList();
    // will hold the words of the line
    char **words;
    // number of spaces
    int numSpace = 0;
    char *newLine = addSpaceParens(line);
    int newLen = strlen(newLine);
    // length of `words`
    int lenWords = countSpace(newLine);
    printf("\"%s\"\n", newLine);

    words = splitAtSpace(newLine);

    for (int i = 0; i < countSpace(newLine); i++)
        if (strcmp(words[i], "") != 0)
        {
            // if (strcmp(words[i], "(") != 0)
            // {
                append(tokens, (char *) words[i], STR);
            // }
        }

    free(words);
    free(newLine);
    return tokens;
}