#include "complex.h"

int validComm(char s[]);
int empty(char s[]);
char singleChar(char s[]);
int doubleChar(char s[], char* x, char* y);
int triple(char s[], char* w, double* x, double* y);
int charNum(char s[], char* w, double* x);

int main() {
	char command[MAXCOMMLENGTH];/*command input string with max length*/
	char *newComm;
	char *rest;
	/*initializing complex numbers*/
	Complex A = { 0 ,0 };
	Complex B = { 0 ,0 };
	Complex C = { 0 ,0 };
	Complex D = { 0 ,0 };
	Complex E = { 0 ,0 };
	Complex F = { 0 ,0 };
	Complex *ptr[COMP]; /*array of pointers to complex numbers*/
	ptr[0] = &A;
	ptr[1] = &B;
	ptr[2] = &C;
	ptr[3] = &D;
	ptr[4] = &E;
	ptr[5] = &F;
	
	printf("hello, please enter a command below, if you want to stop the program please enter 'stop':\n");
	while (1) {/*while doesn't stop unless you enter the command stop*/
		fgets(command, MAXCOMMLENGTH, stdin);/*collect the input string*/
		if (command == NULL || command == '\0') {/*in case of EOF\NULL*/
			printf("Unexpected termination\n");
			break;
		}
		printf("The command you entered is: %s", command);
		rest = command;
		newComm = strtok_s(rest, " ", &rest);/*splitting the command fron the input*/
		switch (validComm(newComm)) {/*switch case for each command*/
		case 1:/*read_comp*/
		{
			double x = 0, y = 0;
			char w = 0;
			if (triple(rest, &w, &x, &y) > 0) {
				int index = w - 65;
				read_comp(ptr[index], x, y);
			}
		}
			break;
		case 2:/*print_comp*/
		{
			int index = 0;
			index = singleChar(rest) - 65;
			if(index >= 0 && index < 6){
				print_comp(*ptr[index]);
			}
		}
			break;
		case 3: /*add_comp*/
		{
			char x = 0, y = 0;
			if ((doubleChar(rest, &x, &y) > 0) && (x >= 65 && y >= 65)) {
				int index1 = x - 65;
				int index2 = y - 65;
				add_comp(*ptr[index1], *ptr[index2]);
			}
		}
			break;
		case 4:/*sub_comp*/
		{
			char x = 0, y = 0;
			if (doubleChar(rest, &x, &y) > 0 && x >= 65 && y >= 65) {
				int index1 = x - 65;
				int index2 = y - 65;
				sub_comp(*ptr[index1], *ptr[index2]);
			}
		}
			break;
		case 5:/*mult_comp_real*/
		{
			double x = 0;
			char w = 0;
			if (charNum(rest, &w, &x) > 0) {
				int index = w - 65;
				mult_comp_real(*ptr[index], x);
			}
		}
			break;
		case 6:/*mult_comp_img*/
		{
			double x = 0;
			char w = 0;
			if (charNum (rest, &w, &x) > 0) {
				int index = w - 65;
				mult_comp_img(*ptr[index], x);
			}
		}
			break;
		case 7:/*mult_comp_comp*/
		{
			char x = 0, y = 0;
			if (doubleChar(rest, &x, &y) > 0 && x >= 65 && y >= 65) {
				int index1 = x - 65;
				int index2 = y - 65;
				mult_comp_comp(*ptr[index1], *ptr[index2]);
			}
		}
			break;
		case 8:/*abs_comp*/
		{
			int index = 0;
			index = singleChar(rest) - 65;
			if (index >= 0 && index < COMP) {
				abs_comp(*ptr[index]);
			}
		}
			break;
		case 9:/*stop*/
			if (rest == NULL) {
				stop();
			}
			if (empty(rest)) {
				stop();
			}
			else if (empty(rest) == -1) {
				printf("Reached EOF, unexpected termination\n\n");
			}
			else {
				printf("Extraneous text after end of command\n\n");
			}
			break;
		case 10:/*empty string case*/
			printf("Empty string\n");
			printf("please enter a new command\n\n");
			break;
		default:/*no match for any command*/
			printf("Undifined command name\n");
			printf("please enter a new command\n\n");
			break;
		}
	}
	return 0;
}

/*checks the validaty of the command given by the input*/
int validComm(char s[]) {
	int i = 0;
	if (s[i] == '\n') {/*empty*/
		return 10;
	}
	else if (isdigit(s[i]) || s[i] == ',') {/*not the correct start for the command*/
		return 0;
	}
	else if (s[strlen(s) - 1] == ',') {/*comma between the command and the first value*/
		printf("Illigal comma\n\n");
		return 0;
	}
	else if (s[i] == ' ' || s[i] == '\t' || isalpha(s[i])) {
		while (s[i] == ' ' || s[i] == '\t')/*skipping spaces*/
			i++;
		if (isalpha(s[i])) {/*for the switch case*/
			if ((strncmp(s, "read_comp", 9)) == 0) {
				return 1;
			}
			else if ((strncmp(s, "print_comp", 10)) == 0) {
				return 2;
			}
			else if ((strncmp(s, "add_comp", 8)) == 0) {
				return 3;
			}
			else if ((strncmp(s, "sub_comp", 8)) == 0) {
				return 4;
			}
			else if ((strncmp(s, "mult_comp_real", 14)) == 0) {
				return 5;
			}
			else if ((strncmp(s, "mult_comp_img", 13)) == 0) {
				return 6;
			}
			else if ((strncmp(s, "mult_comp_comp", 14)) == 0) {
				return 7;
			}
			else if ((strncmp(s, "abs_comp", 8)) == 0) {
				return 8;
			}
			else if ((strncmp(s, "stop", 4)) == 0) {
				return 9;
			}
		}
	}
	return 0;
}
