/****************************************************
Program name:	penny.c
Author:			Claire Vannette 010971984
Date submitted:	3/7/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio 2015
OS:				Windows 10
Description:	Calculate how long it will take to save $1 mil by depositing pennies.
Input files:	None
Output files:	csis.txt
****************************************************/

/****************************************************
Analysis
	Inputs:			None
	Outputs:		Print to console, csis.txt
	Constraints:	Amount to be accumulate must be entered at runtime, display daily deposit and running total, use tabular format, include a main function, a function to output the table header, a function to generate the table, pass input as double, line up output by decimal point, return the value to main, print to console and csis.txt
	Formulas:		
****************************************************/

/****************************************************
Design
	1. Get user input
		1.1 Print request for the amount of money to accumulate
		1.2 Get input and assign to varible
	2. Print the table header
		2.1 Declare function printHeader()
		2.2 Create the function, printing a tab between each column head
	3. Print each day's count, deposit, and total
		3.1 In a loop, keep a running count of loops/days
		3.2 Every loop, increase the deposit, doubling the previous day's amount
		3.3 Every loop, add the deposit to the running total
		3.4 Every loop, print the day's count, day's deposit, and running total
	4. Print the answer
****************************************************/

/****************************************************
Testing
	Use provided amount, 1,000,000
****************************************************/

/****************************************************
Implementation

****************************************************/

#include <stdio.h>

FILE *fp;

void printHeader();
void tableOutput(double targetTotal);

int main(void) {
	double targetTotal;

	fp = fopen("csis.txt", "w");

	printf("Please enter the amount of money you want to accumulate: ");
	fprintf(fp, "Please enter the amount of money you want to accumulate: ");
	scanf("%lf", &targetTotal);
	fprintf(fp, "%lf\n", targetTotal);

	printHeader();

	tableOutput(targetTotal);

	return 0;
}

void printHeader() {
	printf("DAY\t\t\tDEPOSIT\t\t\tBALANCE\n");
	printf("---\t\t\t-------\t\t\t-------\n");
	fprintf(fp, "DAY\t\t\tDEPOSIT\t\t\tBALANCE\n");
	fprintf(fp, "---\t\t\t-------\t\t\t-------\n");
}

void tableOutput(double targetTotal) {
	double deposit = 0.01, calcTotal = 0;
	int days = 1;

	while (calcTotal < targetTotal) {
		calcTotal += deposit;
		printf("%3d\t\t%15.2lf\t\t%15.2lf\n", days, deposit, calcTotal);
		fprintf(fp, "%3d\t\t%15.2lf\t\t%15.2lf\n", days, deposit, calcTotal);
		++days;
		deposit *= 2;
	}

	days -= 1;
	printf("It took %d days to accumulate at least $%.2lf.\n", days, targetTotal);
	fprintf(fp, "It took %d days to accumulate at least $%.2lf.\n", days, targetTotal);

}