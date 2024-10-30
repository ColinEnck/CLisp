#include "mystring.h"

int lenStr(const char *str)
{
    int len;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}

char *insertStr(const char *str, char c, int index)
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

int countSpace(const char *str)
{
    int count = 0;
    int len = lenStr(str);
    for (int i = 0; i < len - 1; i++)
        if (str[i] == ' ')
            count++;
    return count;
}

int *findParens(const char *str)
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

char *addSpaceParens(const char *str)
{
    // number of parentheses
    int numParen = 0;
    // to store new line with spaces before and after parentheses
    char *newStr;
    // locations of parentheses
    int *locsParen;
    int j = 0, newLen = 0;
    int len = lenStr(str);

    for (int i = 0; i < len; i++)
        if (str[i] == '(' || str[i] == ')')
            numParen++;

    locsParen = findParens(str);
    
    newStr = malloc(len + numParen * 2);
    if (newStr == NULL) exit(1);
    strcpy(newStr, str);
    
    for (int i = 0; i < numParen; i++)
    {
        newStr = insertStr(newStr, ' ', locsParen[i]);
        locsParen = findParens(newStr);
        newStr = insertStr(newStr, ' ', locsParen[i] + 1);
        locsParen = findParens(newStr);
    }

    return newStr;
}

char **splitAtSpace(const char *str)
{
    char **ret;
    // position of last whitespace char
    int last = 0;
    // counter for ret
    int j = 0;
    int count = countSpace(str);
    ret = (char **) malloc(sizeof(char *) * count - 1);
    if (ret == NULL)
    {
        printf("malloc error in splitAtSpace: malloc ret\n");
        exit(1);
    }
    for (int i = 0; i < count; i++)
    {
        ret[i] = malloc(LINSIZ);
        if (ret[i] == NULL)
        {
            printf("malloc error in splitAtSpace: malloc ret[i]\n");
            exit(1);
        }
        bzero(ret[i], LINSIZ);
    }
    for (int i = 1; i < lenStr(str); i++)
    {
        if (str[i] == ' ') 
        {
            strncpy(ret[j], str + last + 1, i - last - 1);
            j++;
            last = i;
        }
    }
    return ret;
}