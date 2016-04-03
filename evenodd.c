/****************************************************
Program name:	evenodd.c
Author:			Claire Vannette 1010971984
Date submitted:	3/20/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio 2015
OS:				Windows 10
Description:	Determine if a user-entered number is even or odd.
Input files:	None
Output files:	None
****************************************************/

#include <stdio.h>

int main(void) {
	int num, test;

	printf("Please enter an integer: ");
	scanf("%d", &num);

	if ((num % 2) == 0) {
		printf("%d is even.\n", num);
	}
	else {
		printf("%d is odd.\n", num);
	}

	return 0;
}