/****************************************************
Program name:	change.c
Author:			Claire Vannette
Date submitted:	2/8/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio Community
OS:				Windows 10
Description:	Minimum number of bills and coins needed for change
Input files:	None
Output files:	csis.txt
****************************************************/

/****************************************************
Analysis
	Inputs:			No user inputs
	Outputs:		print to console and csis.txt - count of twenties, tens, fives, singles, quarters, dimes, nickels, and pennies
	Constraints:	no subtraction, no global variables 
	Formulas:		total / denomination, total % denomination
****************************************************/

/****************************************************
Design
	1. Subtract cost from amount tendered.
		1.1 Assign to "total" and "change."
	2. Turn into an integer.
		2.1 Multiple total by 100.
	3. Determine the number of twenties.
		3.1 Divide the total by 2000, with an integer result. This is the number of twenties.
		3.2 Calculate total modulo 2000. This is the new total.
	4. Determine the number of tens.
		4.1 Divide the total by 1000, with an integer result. This is the number of tens.
		4.2 Calculate total modulo 1000. This is the new total.
	5. Determine the number of fives.
		5.1 Divide the total by 500, with an integer result. This is the number of fives.
		5.2 Calculate total modulo 500. This is the new total.
	6. Determine the number of ones.
		6.1 Divide the total by 100, with an integer result. This is the number of ones.
		6.2 Calculate total modulo 100. This is the new total.
	7. Determine the number of quarters.
		7.1 Divide the total by 25, with an integer result. This is the number of quarters.
		7.2 Calculate total modulo 25. This is the new total.
	8. Determine the number of dimes.
		8.1 Divide the total by 10, with an integer result. This is the number of dimes.
		8.2 Calculate total modulo 10. This is the new total.
	9. Determine the number of nickels.
		9.1 Divide the total by 5, with an integer result. This is the number of nickels.
		9.2 Calculate total modulo 5. This is the new total.
	10. Determine the number of pennies.
		10.1 The current total equals the number of pennies.
	11. Print the result.
		11.1 "When you buy a $(cost) item with $(tendered), the change is $(tendered - cost). The minimum number of bills and coins required to make this change is x twenties, x tens, x fives, x ones, x quarters, x dimes, x nickels, and x pennies."
****************************************************/

/****************************************************
Testing

****************************************************/

/****************************************************
Implementation

****************************************************/

#include <stdio.h>

int main(void)
{
	FILE * csis;

	float tendered = 100, cost = 21.17, change, total;
	int twenties, tens, fives, ones, quarters, dimes, nickels, pennies;

	total = change = tendered - cost;

	total = change * 100;

	twenties = (int) total / 2000;
	total = (int) total % 2000;
	tens = (int) total / 1000;
	total = (int) total % 1000;
	fives = (int) total / 500;
	total = (int) total % 500;
	ones = (int) total / 100;
	total = (int) total % 100;
	quarters = (int) total / 25;
	total = (int) total % 25;
	dimes = (int) total / 10;
	total = (int) total % 10;
	nickels = (int) total / 5;
	total = (int) total % 5;
	pennies = (int) total;

	printf("When you buy a $%.2f item and pay $%.2f, the change is $%.2f. The minimum bills and coins required to make this change is %d twenties, %d tens, %d fives, %d ones, %d quarters, %d dimes, %d nickels, and %d pennies.\n", cost, tendered, change, twenties, tens, fives, ones, quarters, dimes, nickels, pennies);

	csis = fopen("csis.txt", "w+");
	fprintf(csis, "When you buy a $%.2f item and pay $%.2f, the change is $%.2f.The minimum bills and coins required to make this change is %d twenties, %d tens, %d fives, %d ones, %d quarters, %d dimes, %d nickels, and %d pennies.\n", cost, tendered, change, twenties, tens, fives, ones, quarters, dimes, nickels, pennies);
	fclose(csis);

	return 0;
}