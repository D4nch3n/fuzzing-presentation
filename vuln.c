#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define NAME_SIZE 16

char name[NAME_SIZE] = "TEMPINIT"; //16 should be enough for most names
void (*fun_ptr)();

void secret() {
	puts("You found my secret! \n");
}
void initialize(char* arg) {
        strncpy(name, arg, 24); //Since we are writing to a global variable, and global variables aren't stored on the stack, no harm in writing a bit more, right?
}
void foo1() {
	printf("Hello, %s! You are in function 1! \n", name);
}

void foo2() {
	printf("You have called function 2, %s \n", name);
}

void foo3() {
	printf("Sorry, %s! This is function 3! \n", name);
}

void call_correct_function(int val) {
	switch(val) {
		case 1:
			fun_ptr = &foo1;
			break;
		case 2:
			fun_ptr = &foo2;
			break;
		case 3:
			fun_ptr = &foo3;
			break;
	}
	(*fun_ptr)();
}
int main(int argc, char *argv[]) {
	if(argc != 3) // we must only take two command line arguements
	{
	  exit(0);
	}
	int val = atoi(argv[1]); //Converts the first command line argument into an integer
	initialize(argv[2]); //Set the second command line arguement as the name
	call_correct_function(val);
	return 0;
}
