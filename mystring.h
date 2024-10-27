#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINSIZ 64

// returns length of a string
int lenStr(const char *str);

// counts the number of space chars in a string
int countSpace(const char *str);

// returns a list with the positions of all parentheses in `str`
int *findParens(const char *str);

// inserts char c in str at index
// returns new string
char *insertStr(const char *str, char c, int index);

// adds spaces before and after each parenthesis
char *addSpaceParens(const char *str);

// splits a string up by space chars
// returns an array of strings
// assumes that the string starts and ends with a space
char **splitAtSpace(const char *str);

#endif