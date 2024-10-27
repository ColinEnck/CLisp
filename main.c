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
        parse(line, len);
    }

    return 0;
}

struct Token *parse(char *line, int len)
{
    // will hold the tokenized code
    struct Token *tokens = newList();
    // will hold the words of the line
    char **words;
    // number of spaces
    int numSpace = 0;
    char *newLine = addSpaceParens(line);
    int newLen = lenStr(newLine);
    // length of `words`
    int lenWords = countSpace(newLen);
    printf("\"%s\"\n", newLine);

    words = splitAtSpace(newLine);
    for (int i = 0; i < countSpace(newLine); i++)
        printf("\"%s\"\n", words[i]); 

    return tokens;
}
