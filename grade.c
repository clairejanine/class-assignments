/****************************************************
Program name:	grade.c
Author:			Claire Vannette 010971984
Date submitted:	3/6/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio 2015
OS:				Windows 10
Description:	Calculate average grade
Input files:	None
Output files:	csis.txt
****************************************************/

/****************************************************
Analysis
	Inputs:			User input of grades
	Outputs:		Average of grades
	Constraints:	Use a sentinel value (-1), use a while loop, scores 0-100, output average to two decimal places, output everything to csis.txt, use provided main function
	Formulas:		sum / number of grades = average
****************************************************/

/****************************************************
Design
	1. Include provided main function.
		1.1 For loop repeats for 4 averages.
	2. Prompt user to enter test scores.
		2.1 In a while loop, add each score to the ongoing sum.
		2.2 User enters -1 to signal end of scores.
	3. Calculate average of scores and display to user.
		3.1 Divide sum by number of scores (loops).
		3.2 Print to console and csis.txt.
****************************************************/

/****************************************************
Testing
	Use provided series of grades, verify with calculator.
****************************************************/

/****************************************************
Implementation

****************************************************/

#include <stdio.h>

FILE *fp;

void calculateAverage();

int main(void) { // provided function
	int i;

	fp = fopen("csis.txt", "w");
	for (i = 1; i <= 4; ++i) {
		calculateAverage();
	}
	fclose(fp);
	return 0;
}

void calculateAverage() { // created function
	int score = 0, sum = 0, count = 0; // declare and initialize variables
	float average;

	while (score != -1) { // ensures that loop will stop after user enters -1
		printf("Enter a test score, from 1 to 100. Enter -1 to end. ");
		fprintf(fp, "Enter a test score, from 1 to 100. Enter -1 to end. ");
		scanf("%d", &score);
		fprintf(fp, "%d", score);
		sum += score; // adds the score to the running sum
		++count; // counts the number of loops
	}

	if (count > 1) { // count will be at least 2 if user has entered at least 1 valid score
		average = (float)((sum + 1) / (count - 1)); // compensate for the -1
		printf("The average of these %d scores is %.2f.\n", count - 1, average);
		fprintf(fp, "The average of these %d scores is %.2f.\n", count - 1, average);

	}

	else { // in case user only enters -1
		printf("You have entered no scores.\n");
		fprintf(fp, "You have entered no scores.\n");
	} 

}