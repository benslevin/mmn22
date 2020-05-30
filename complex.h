#include "validations.h"

/*creating a struct for a complex numbner*/
typedef struct
{
	double real;/*real part of complex*/
	double img;/*imaginary part of complex number*/
} Complex;/*name of struct*/

void read_comp(Complex*, double, double);
void print_comp(Complex);
void add_comp(Complex, Complex);
void sub_comp(Complex, Complex);
void mult_comp_real(Complex, double);
void mult_comp_img(Complex, double);
void mult_comp_comp(Complex, Complex);
void abs_comp(Complex);
void stop(void);
