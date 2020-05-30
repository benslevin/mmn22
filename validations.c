#include "validations.h"

/*checking that there is no value after the command given
for comand: stop*/
int empty(char s[]) {
	int i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != '\n' && s[i] != '\0') {
		return 0;
	}
	else if (s[i] == '\n' || s[i] == '\0') {
		return 1;
	}
	else if (EOF) {
		return -1;
	}
	else return 0;

}

/*checking the value of the single character after the command given
for comand: print_comp, abs_comp*/
char singleChar(char s[]) {
	int i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == ',') {/*no comma between the command and the first value*/
		printf("Illigal comma\n\n");
		return 0;
	}
	if (s[i] == '\n' || s[i] == '\0') {/*missing a parameter*/
		printf("Missing parameter\n\n");
		return 0;
	}
	if ((s[i]) >= 'A' && (s[i]) < 'G') {/*correct value of the parameter*/
		if (s[i+1] == '\n')
			return s[i];
		else
			printf("Extraneous text after end of command\n\n");/*extra text*/
		return 0;
	}
	else if ((s[i]) >= 'G' || !isupper(s[i])){/*out of bong value for parameter*/
		printf("Undefined complex variable\n\n");
		return 0;
	}
	return 0;
}

/*checking the value of 2 characters after the command given
for comand: add_comp, sub_comp, mult_comp_comp*/
int doubleChar(char s[] , char* x, char* y) {
	int i = 0;
	while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
		i++;
	if (s[i] == ',') {/*no comma between the command and the first value*/
		printf("Illigal comma\n\n");
		return 0;
	}
	if (s[i] == '\n' || s[i] == EOF) {/*missing a parameter*/
		printf("Missing parameter\n\n");
		return 0;
	}
	if ((s[i]) >= 'A' && (s[i]) < 'G') {/*correct value of the parameter*/
		*x = s[i++];
		while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
			i++;
		if (s[i] == ',') {
			i++;
			while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
				i++;
			if (s[i] == ',') {/*to many commas*/
				printf("Multiple consecutive commas\n\n");
				return 0;
			}
			else if ((s[i]) >= 'A' && (s[i]) < 'G') {/*correct value of the parameter*/
				*y = s[i++];
				while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
					i++;
				if (s[i] == '\n') {
					return 1;
				}
				else {/*extra text*/
					printf("Extraneous text after end of command\n\n");
					return 0;
				}
			}
			else if (s[i] == '\n' || s[i] == '\0') {/*missing a parameter*/
				printf("Missing parameter\n\n");
				return 0;
			}
			else if (!isalpha(s[i])) {/*invalid parameter*/
				printf("Invalid parameter - not a Character\n\n");
				return 0;
			}
		}
		else if (s[i] != ',') {/*missing comma*/
			printf("Missing comma\n\n");
			return 0;
		}
		
	}
	else if ((s[i]) >= 'G' || !isalpha(s[i])) {/*out of bong value for parameter*/
		printf("Undefined complex variable\n\n");
		return 0;
	}
	return 0;
}

/*checking the value of one character and 2 numbers after the command given
for comand: read_comp*/
int triple(char s[], char* w, double* x, double* y) {
	int i = 0;
	int k = 0, l = 0;
	char num1[sizeof(double)], num2[sizeof(double)];
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == ',') {/*illigal comma*/
		printf("Illigal comma\n\n");
		return 0;
	}
	if (s[i] == '\n' || s[i] == EOF) {/*missing a parameter*/
		printf("Missing parameter\n\n");
		return 0;
	}
	if ((s[i]) >= 'A' && (s[i]) < 'G') {
		*w = s[i];
		i++;
		if (s[i] == '\n' || s[i] == EOF) {/*missing a parameter*/
			printf("Missing parameter\n\n");
			return 0;
		}
		while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
			i++;
		if (s[i++] == ',') {
			while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
				i++;
			if (isdigit(s[i]) || s[i] == '-') {/*collecting first number*/
				while (isdigit(s[i]) || s[i] == '-') {
					num1[k++] = s[i++];
				}
				if (s[i] == '.') {/*checks if there is a decimal part for the number*/
					num1[k++] = s[i++];
					while (isdigit(s[i])) {
						num1[k++] = s[i++];
					}
					*x = atof(num1);
					i++;
				}
				else if (s[i] == ',') {
					*x = atof(num1);
					i++;
				}
				else return 0;
				while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
					i++;
				if (isdigit(s[i]) || s[i] == '-') {/*collecting second number*/
					while (isdigit(s[i]) || s[i] == '-') {
						num2[l++] = s[i++];
					}
					if (s[i] == '.') {/*checks if there is a decimal part for the number*/
						num2[l++] = s[i++];
						while (isdigit(s[i])) {
							num2[l++] = s[i++];
						}
						*y = atof(num2);
						return 1;
					}
					else if (s[i] == '\n' || s[i] == '\0' || s[i] == ' ' || s[i] == '\t') {
						*y = atof(num2);
						if (s[i] == '\n') {
							return 1;
						}
						else if (s[i] == ' ' || s[i] == '\t') {
							while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
								i++;
							if (s[i] == '\n') {
								return 1;
							}
							else {/*extra text*/
								printf("Extraneous text after end of command\n\n");
								return 0;
							}

						}
						else {/*extra text*/
							printf("Extraneous text after end of command\n\n");
							return 0;
						}
					}
					else {/*extra text*/
						printf("Extraneous text after end of command\n\n");
						return 0;
					}
				}
				else if (s[i] == '\n' || s[i] == '\0') {/*missing a parameter*/
					printf("Missing parameter\n\n");
				}
				else {/*invalid parameter*/
					printf("Invalid parameter - not a number\n\n");
					return 0;
				}
			}
			else if (s[i] == '\n' || s[i] == '\0') {/*missing a parameter*/
				printf("Missing parameter\n\n");
			}
			else {/*invalid parameter*/
				printf("Invalid parameter - not a number\n\n");
				return 0;
			}
		}
		else {/*missing comma*/
			printf("Missing comma\n\n");
			return 0;
		}
	}
	else if ((s[i]) >= 'G' || !isalpha(s[i])) {/*out of bong value for parameter*/
		printf("Undefined complex variable\n\n");
		return 0;
	}
	return 0;
}

/*checking the value of one character and one number after the command given
for comand: mult_comp_real, mult_comp_img*/
int charNum(char s[], char* w, double* x) {
	int i = 0;
	int k = 0;
	char num1[sizeof(double)];
	while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
		i++;
	if (s[i] == ',') {/*illigal comma*/
		printf("Illigal comma\n\n");
		return 0;
	}
	if (s[i] == '\n' || s[i] == EOF) {/*missing a parameter*/
		printf("Missing parameter\n\n");
		return 0;
	}
	else if ((s[i]) >= 'A' && (s[i]) < 'G') {
			*w = s[i];
			i++;
			while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
				i++;
			if (s[i++] == ',') {
				while (s[i] == ' ' || s[i] == '\t')/*skip spaces*/
					i++;
				if (isdigit(s[i]) || s[i] == '-') {/*collecting number*/
					while (isdigit(s[i]) || s[i] == '-') {
						num1[k++] = s[i++];
					}
					if (s[i] == '.') {/*checks if there is a decimal part for the number*/
						num1[k++] = s[i++];
						while (isdigit(s[i])) {
							num1[k++] = s[i++];
						}
						*x = atof(num1);
						return 1;
					}
					else if (s[i] == '\n' || s[i] == '\0') {
						*x = atof(num1);
						return 1;
					}
					else if (s[i] == ' ' || s[i] == '\t') {
						*x = atof(num1);
						while (s[i] == ' ' || s[i] == '\t')
							i++;
						if (s[i] == '\n' || s[i] == '\0')
							return 1;
						else return 0;
					}
					else {/*extra text*/
						printf("Extraneous text after end of command\n\n");
						return 0;
					}
				}
				else {/*invalid parameter*/
					printf("Invalid parameter - not a number\n\n");
					return 0;
				}
			}
	}
	else if ((s[i]) >= 'G' || !isalpha(s[i])) {/*out of bong value for parameter*/
		printf("Undefined complex variable\n\n");
		return 0;
	}
	return 0;
}
