#include "complex.h"

void read_comp(_complex comp, double a , double b) {
	comp.real = a;
	comp.img = b;
}

void print_comp(_complex comp) {
	printf("%.2f + (%.2f)i\n", comp.real, comp.img);
}

void add_comp(_complex comp1, _complex comp2) {
	_complex temp;
	temp.real = comp1.real + comp2.real;
	temp.img = comp1.img + comp2.img;

	print_comp(temp);
}

void sub_comp(_complex comp1, _complex comp2) {
	_complex temp;
	temp.real = comp1.real - comp2.real;
	temp.img = comp1.img - comp2.img;

	print_comp(temp);
}

void mult_comp_real(_complex comp, double x) {
	_complex temp;
	temp.real = comp.real * x;
	temp.img = comp.img * x;

	print_comp(temp);
}

void mult_comp_img(_complex comp, double x) {
	_complex temp;
	temp.real = x * comp.img * (-1);
	temp.img = x * comp.real;

	print_comp(temp);
}

void mult_comp_comp(_complex comp1, _complex comp2) {
	_complex temp;
	temp.real = (comp1.real * comp2.real) - (comp1.img * comp2.img);
	temp.img = (comp1.real * comp2.img) + (comp1.img * comp2.real);

	print_comp(temp);
}

void abs_comp(_complex comp) {
	double temp;
	temp = sqrt(pow(comp.real,2) + pow(comp.img,2));
	
}

void stop(void) {
	printf("The program has ended\n");
	exit(0);
}



