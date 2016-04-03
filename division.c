/****************************************************
Program name:	division.c
Author:			Claire Vannette 010971984
Date submitted:	3/20/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio 2015
OS:				Windows 10
Description:	Calculate the quotient of two user-input numbers.
Input files:	None
Output files:	None
****************************************************/

#include <stdio.h>

int main(void) {
	int dividend, divisor;
	double quotient = 0;

	printf("I am a program that performs division.\n");
	printf("Please enter an integer for the dividend: ");
	scanf("%d", &dividend);
	printf("Please enter an integer for the divisor: ");
	scanf("%d", &divisor);

	divisor == 0 ? printf("Cannot divide by zero.\n") : printf("The quotient is %.2lf\n", (double) dividend / divisor);

	return 0;
}