#include "complex.h"

/*inserting a value in the complex number, changing the actual value*/
void read_comp(Complex *comp, double a , double b) {
	comp -> real = a;
	comp -> img = b;
}

/*printing the complex number, creating a copy, not changing the actual value of the complex*/
void print_comp(Complex comp) {
	printf("the answer is: ");
	printf("%.2f + (%.2f)i\n", comp.real, comp.img);
}

/*adding 2 complex numbers, creating a copy, not changing the actual value of the complex*/
void add_comp(Complex comp1, Complex comp2) {
	Complex temp;
	temp.real = comp1.real + comp2.real;
	temp.img = comp1.img + comp2.img;

	print_comp(temp);
}

/*subtracting 2 complex numbers, creating a copy, not changing the actual value of the complex*/
void sub_comp(Complex comp1, Complex comp2) {
	Complex temp;
	temp.real = comp1.real - comp2.real;
	temp.img = comp1.img - comp2.img;

	print_comp(temp);
}

/*multiplying a complex number with a real number, creating a copy, not changing the actual value of the complex*/
void mult_comp_real(Complex comp, double x) {
	Complex temp;
	temp.real = comp.real * x;
	temp.img = comp.img * x;

	print_comp(temp);
}

/*multiplying a complex number with an imaginary number, creating a copy, not changing the actual value of the complex*/
void mult_comp_img(Complex comp, double x) {
	Complex temp;
	temp.real = x * comp.img * (-1);
	temp.img = x * comp.real;

	print_comp(temp);
}
/*multiplying a complex number with a complex number, creating a copy, not changing the actual value of the complex*/
void mult_comp_comp(Complex comp1, Complex comp2) {
	Complex temp;
	temp.real = (comp1.real * comp2.real) - (comp1.img * comp2.img);
	temp.img = (comp1.real * comp2.img) + (comp1.img * comp2.real);

	print_comp(temp);
}

/*calculating the absolute value of the complex number, creating a copy, not changing the actual value of the complex*/
void abs_comp(Complex comp) {
	double temp;
	temp = sqrt(pow(comp.real,2) + pow(comp.img,2));

	printf("The squre root is: %.2f\n", temp);
}

/*stoping the program*/
void stop(void) {
	printf("The program has ended\n");
	exit(0);
}



