#include "complex.h"

int empty(char s[]);
char singleChar(char s[]);
int doubleChar(char s[], char x, char y);
int triple(char s[], char w, double x, double y);
int charNum(char s[], char w, double x);

int empty(char s[]) {
	int i = 0;
	while (s[i++] == ' ' || s[i++] == '\t')
		;
	if (s[i] == '\n' || s[i] == EOF) {
		return 1;
	}
	else if (EOF) {
		return -1;
	}
	else return 0;

}
char singleChar(char s[]) {
	int i = 0;
	while (s[i++] == ' ' || s[i++] == '\t')
		;
	if (s[i] == '\n' || s[i] == EOF) {
		printf("Missing parameter\n");
		return 0;
	}
	if (isupper(s[i]) >= 'A' && isupper(s[i]) < 'G') {
		return s[i];
	}
	else if (isupper(s[i]) >= 'G' || !isalpha(s[i])){
		printf("Undefined complex variable\n");
		return 0;
	}

}

int doubleChar(char s[] , char x, char y) {
	int i = 0;
	while (s[i++] == ' ' || s[i++] == '\t')
		;
	if (s[i] == '\n' || s[i] == EOF) {
		printf("Missing parameter\n");
		return 0;
	}
	if (isupper(s[i]) >= 'A' && isupper(s[i]) < 'G') {
		x = s[i++];
		while (s[i++] == ' ' || s[i++] == '\t')
			;
		if (s[i++] == ',') {
			while (s[i++] == ' ' || s[i++] == '\t')
				;
			if (s[i++] == ',') {
				printf("Multiple consecutive commas");
			}
			else if (isupper(s[i]) >= 'A' && isupper(s[i]) < 'G') {
				y = s[i++];
				while (s[i++] == ' ' || s[i++] == '\t')
					;
				if (s[i] == '\n') {
					return 1;
				}
			}
		}
		else if (!isalpha(s[i])) {
			printf("Invalid parameter - not a Character");
			return 0;
		}
		
	}
	else if (isupper(s[i]) >= 'G' || !isalpha(s[i])) {
		printf("Undefined complex variable\n");
		return 0;
	}
}

int triple(char s[], char w, double x, double y) {
	int i = 0;
	int k = 0, l = 0;
	char num1[sizeof(double)], num2[sizeof(double)];
	while (s[i++] == ' ' || s[i++] == '\t')
		;
	if (s[i] == '\n' || s[i] == EOF) {
		printf("Missing parameter\n");
		return 0;
	}
	if (isupper(s[i]) >= 'A' && isupper(s[i]) < 'G') {
		w = s[i];
		i++;
		while(s[i++] == ' ' || s[i++] == '\t')
			;
		if (s[i++] == ',') {
			while (s[i++] == ' ' || s[i++] == '\t')
				; 
			if (isdigit(s[i++])) {
				while (isdigit(s[i])) {
					num1[k++] = s[i++];
				}
				if (s[i] == '.') {
					num1[k++] = s[i++];
					while (isdigit(s[i])) {
						num1[k++] = s[i++];
					}
					x = atof(num1);
				}
				while (s[i++] == ' ' || s[i++] == '\t')
					;
				if (isdigit(s[i++])) {
					while (isdigit(s[i])) {
						num2[l++] = s[i++];
					}
					if (s[i] == '.') {
						num2[l++] = s[i++];
						while (isdigit(s[i])) {
							num2[l++] = s[i++];
						}
						y = atof(num2);
						return 1;
					}
				}
			}
		}
	}
	else if (isupper(s[i]) >= 'G' || !isalpha(s[i])) {
		printf("Undefined complex variable\n");
		return 0;
	}
}

int charNum(char s[], char w, double x) {
	int i = 0;
	int k = 0;
	char num1[sizeof(double)];
	while (s[i++] == ' ' || s[i++] == '\t')
		;
	if (s[i] == '\n' || s[i] == EOF) {
		printf("Missing parameter\n");
		return 0;
	}
	else if (isupper(s[i]) >= 'A' && isupper(s[i]) < 'G') {
			w = s[i];
			i++;
			while (s[i++] == ' ' || s[i++] == '\t')
				;
			if (s[i++] == ',') {
				while (s[i++] == ' ' || s[i++] == '\t')
					;
				if (isdigit(s[i++])) {
					while (isdigit(s[i])) {
						num1[k++] = s[i++];
					}
					if (s[i] == '.') {
						num1[k++] = s[i++];
						while (isdigit(s[i])) {
							num1[k++] = s[i++];
						}
						x = atof(num1);
						return 1;
					}
				}
			}
	}
	else if (isupper(s[i]) >= 'G' || !isalpha(s[i])) {
		printf("Undefined complex variable\n");
		return 0;
	}
}
