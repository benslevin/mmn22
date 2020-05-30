#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXCOMMLENGTH 50
#define COMP 6

int empty(char s[]);
char singleChar(char s[]);
int doubleChar(char s[], char* x, char* y);
int triple(char s[], char* w, double* x, double* y);
int charNum(char s[], char* w, double* x);
