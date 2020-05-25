#include "complex.h"

int validComm(char s[], char new[]);
int empty(char s[]);
char singleChar(char s[]);
int doubleChar(char s[], char x, char y);
int triple(char s[], char w, double x, double y);
int charNum(char s[], char w, double x);

int main() {
	int i = 0;
	char command[MAXCOMMLENGTH];
	char newComm[MAXCOMMLENGTH];
	_complex A = { 0 ,0 };
	_complex B = { 0 ,0 };
	_complex C = { 0 ,0 };
	_complex D = { 0 ,0 };
	_complex E = { 0 ,0 };
	_complex F = { 0 ,0 };
	_complex *ptr[COMP];
	ptr[0] = &A;
	ptr[1] = &B;
	ptr[2] = &C;
	ptr[3] = &D;
	ptr[4] = &E;
	ptr[5] = &F;

	printf("hello, please enter a command bellow, if you want to stop the program please enter 'stop':\n");
	while (1) {
		fgets(command, MAXCOMMLENGTH, stdin);
		printf("The command you entered is: %s", command);
		switch (validComm(command, newComm)) {
		case 1:
		{
			double x = 0, y = 0;
			char w;
			if (triple(newComm, w, x, y) > 0) {
				read_comp(*ptr[w - 65], x, y);
			}
		}
		case 2:
			if (ptr[singleChar(newComm) - 65] >= 0 && ptr[singleChar(newComm) - 65] < 6) {
				print_comp(*ptr[singleChar(newComm) - 65]);
			}
		case 3: 
		{
			char x, y;
			if (doubleChar(newComm, x, y) > 0) {
				add_comp(*ptr[x - 65], *ptr[y - 65]);
			}
		}
		case 4:
		{
			char x, y;
			if (doubleChar(newComm, x, y) > 0) {
				sub_comp(*ptr[x - 65], *ptr[y - 65]);
			}
		}
		case 5:
		{
			double x = 0, y = 0;
			char w;
			if (charNum(newComm, w, x) > 0) {
				mult_comp_real(*ptr[w - 65], x);
			}
		}
		case 6:
		{
			double x = 0, y = 0;
			char w;
			if (charNum(newComm, w, x) > 0) {
				mult_comp_img(*ptr[w - 65], x);
			}
		}
		case 7:
		{
			char x, y;
			if (doubleChar(newComm, x, y) > 0) {
				mult_comp_comp(*ptr[x - 65], *ptr[y - 65]);
			}
		}
		case 8:
			if (ptr[singleChar(newComm) - 65] >= 0 && ptr[singleChar(newComm) - 65] < 6) {
				abs_comp(*ptr[singleChar(newComm) - 65]);
			}
		case 9:
			if (empty(newComm)) {
				stop;
			}
			else if (empty(newComm) == -1) {
				printf("Reached EOF, unexpected termination\n");
			}
			else {
				printf("Extraneous text after end of command\n");
			}
		default:
			printf("Undifined command name\n");
			printf("please enter a new command\n");
		}
	}
	return 0;
}


int validComm(char s[], char new[]) {
	int i = 0, j = 0;
	char word[MAXCOMMLENGTH];
	if (s[i] == '\n') {
		printf("Empty string\n");
		printf("please enter a new command\n");
	}  
	else if (isdigit(s[i]) || s[i] == ',') {
		printf("Unidifined command name\n");
		printf("please enter a new command\n");
	}
	else if (s[i] == ' ' || s[i] == '\t' || isalpha(s[i])) {
			while (s[i++] == ' ' || s[i++] == '\t')
			;
			if (isalpha(s[i])) {
				while (!isdigit(s[i]) || !isupper(s[i]) || s[i] != ',' || s[i] != ' ') {
				word[j] = s[i];
				i++;
				j++;
			}
				if ((strcmp(word, "read_comp")) == 0) {
					return 1;
				}
				else if ((strcmp(word, "print_comp")) == 0) {
					return 2;
				}
				else if ((strcmp(word, "add_comp")) == 0) {
					return 3;
				}
				else if ((strcmp(word, "sub_comp")) == 0) {
					return 4;
				}
				else if ((strcmp(word, "mult_comp_real")) == 0) {
					return 5;
				}
				else if ((strcmp(word, "mult_comp_img")) == 0) {
					return 6;
				}
				else if ((strcmp(word, "mult_comp_comp")) == 0) {
					return 7;
				}
				else if ((strcmp(word, "abs_comp")) == 0) {
					return 8;
				}
				else if ((strcmp(word, "stop")) == 0) {
					return 9;
				}
			strcpy(new, s[i]);
		}
	}
	return 0;
}
