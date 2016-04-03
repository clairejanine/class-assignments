/****************************************************
Program name:	pythag.c
Author:			Claire Vannette 010971984
Date submitted:	3/20/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio 2015
OS:				Windows 10
Description:	Given the lengths of two sides of a right triangle, provide the length of the third side
Input files:	None
Output files:	None
****************************************************/

#include <stdio.h>
#include <math.h>

double calcLength(double legA, double legB, double hypoteneuse);

int main(void) {
	double legA = 0, legB = 0, hypoteneuse= 0, result;
	int response;

	printf("Please enter the length of Leg A of a right triangle: ");
	scanf("%lf", &legA);

	if (legA <= 0) {
		printf("That is not a valid length. Goodbye.\n");
		exit(1);
	}

	printf("Do you know the length of Leg B of this triangle? Enter 1 for Yes or 0 for No. "); // this is kludgy and not user friendly but for some reason I can't get characters to input correctly with scanf
	scanf("%d", &response); 

	if (response == 1) {
		printf("Please enter the length of Leg B: ");
		scanf("%lf", &legB);
	}
	else {
		printf("Please enter the length of the hypoteneuse: ");
		scanf("%lf", &hypoteneuse);

		if (hypoteneuse <= legA) {
			printf("Your hypoteneuse cannot be shorter than Leg A. Goodbye.\n");
			exit(1);
		}
	}

	result = calcLength(legA, legB, hypoteneuse);

	if (response == 'Y' || response == 'y') {
		printf("Hypoteneuse = %.2lf\n", result);
	}
	else {
		printf("Leg B = %.2lf\n", result);
	}

	return 0;
}

double calcLength(double legA, double legB, double hypoteneuse) {
	legA, legB, hypoteneuse;
	double result;

	if (hypoteneuse == 0) {
		result = sqrt((pow(legA, 2) + pow(legB, 2)));
	}
	else {
		result = sqrt((pow(hypoteneuse, 2) - pow(legA, 2)));
	}

	return result;
}
