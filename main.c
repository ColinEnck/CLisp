#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "token.h"
// largest line of a lisp line
#define LINSIZ 80

// returns length of a string
int lenStr(char *str);

// returns a list with the positions of all parentheses in `str`
int *findParens(char *str);

// inserts char c in str at index
// returns new string
char *insertStr(char *str, char c, int index);

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

int lenStr(char *str)
{
    int len;
    for (len = 1; str[len] != '\0'; len++);
    return len;
}

int *findParens(char *str)
{
    int *locs;
    int j = 0, num = 0;
    int len = lenStr(str);

    for (int i = 0; i < len; i++)
        if (str[i] == ')' || str[i] == '(')
            num++;
    
    locs = (int *) malloc(sizeof(int) * num);

    for (int i = 0; i < len; i++)
        if (str[i] == ')' || str[i] == '(')
        {
            locs[j] = i;
            j++;
        }
    
    return locs;
}

char *insertStr(char *str, char c, int index)
{
    int len;
    char *newStr;

    len = lenStr(str);
    newStr = malloc(len+1);
    if (newStr == NULL) exit(1);

    strncpy(newStr, str, index);
    newStr[index] = c;
    strncpy(newStr + index + 1, str + index, len - index);

    return newStr;
}

struct Token *parse(char *line, int len)
{
    // will hold the tokenized code
    struct Token *tokens = newList();
    // will hold the words of the line
    char **words;
    // number of parentheses
    int numParen = 0;
    // number of spaces
    int numSpace = 0;
    // to store new line with spaces before and after parentheses
    char *newLine;
    // locations of parentheses
    int *locsParen;
    // locations of spaces
    int *locsSpace;
    // location of last space
    int last;
    int j = 0, newLen = 0;

    for (int i = 0; i < len; i++)
        if (line[i] == '(' || line[i] == ')')
            numParen++;

    locsParen = findParens(line);
    
    newLine = malloc(len + numParen * 2);
    if (newLine == NULL) exit(1);
    strcpy(newLine, line);
    
    for (int i = 0; i < numParen; i++)
    {
        newLine = insertStr(newLine, ' ', locsParen[i]);
        locsParen = findParens(newLine);
        newLine = insertStr(newLine, ' ', locsParen[i] + 1);
        locsParen = findParens(newLine);
    }

    newLen = lenStr(newLine);

    for (int i = 0; i < newLen; i++)
        if (newLine[i] == ' ')
            numSpace++;

    locsSpace = (int *) malloc(sizeof(int) * numSpace);
    if (locsSpace == NULL) exit(1); 

    for (int i = 0; i < newLen; i++)
        if (newLine[i] == ')' || newLine[i] == '(')
        {
            locsSpace[j] = i;
            j++;
        }

    words = (char **) malloc(sizeof(char *) * (numSpace - 1));
    if (words == NULL) exit(1);
    for (int i = 0; i < numSpace - 1; i++)
    {
        words[i] = malloc(LINSIZ);
        if (words[i] == NULL) exit(1);
        bzero(words[i], LINSIZ);
    }

    printf("%s\n", newLine);

    j = 0;
    for (int i = 1; i < newLen; i++)
    {
        if (newLine[i] == ' ')
        {
            strncpy(words[j], newLine + last + 1, i - last);
            last = i;
            j++;
        }
    }
    
    for (size_t i = 0; i < numSpace - 1; i++)
    {
        printf("%s\n", words[i]);
    }
    

    return tokens;
}