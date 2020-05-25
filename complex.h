#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXCOMMLENGTH 50
#define COMP 6

void read_comp(_complex, double, double);
void print_comp(_complex);
void add_comp(_complex, _complex);
void sub_comp(_complex, _complex);
void mult_comp_real(_complex, double);
void mult_comp_img(_complex, double);
void mult_comp_comp(_complex, _complex);
void abs_comp(_complex);
void stop(void);

typedef struct 
{
	double real;
	double img;
} _complex;

