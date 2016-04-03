/****************************************************
Program name:	monthlyPayment1.c
Author:			Claire Vannette
Date submitted:	2/20/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio Community
OS:				Windows 10
Description:	Calculate monthly payments.
Input files:	None
Output files:	None
****************************************************/

/****************************************************
Analysis
	Inputs:			Prompt user for purchase price, the down payment, the annual interest rate and the total number of payments.
	Outputs:		Print to console: the amount borrowed and the monthly payment.
	Constraints:	Implement everything within main(). Use the math.h library to assist with the calculation. Do not use any other math library. Print to two decimal places. Include dollar sign.
	Formulas:		payment = iP / (1 - (1 + i)^(-n)) 
****************************************************/

/****************************************************
Design
	1. Prompt user to provide purchase price, down payment, interest rate, and number of payments.
		1.1 Enter purchase price.
		1.2 Enter down payment.
		1.3 Enter interest rate.
		1.4 Enter number of payments.
	2. Calculate the amount borrowed.
		2.1 Subtract down payment from purchase price.
	3. Calculate the monthly interest rate.
		3.1 Divide the annual rate by 12.
	4. Calculate the monthly payment.
		4.1 Use the pow() function
	4. Print the amount borrowed and monthly payment.

****************************************************/

/****************************************************
Testing
	Run program with various prices and down payments; verify results with online loan calculator
****************************************************/

/****************************************************
Implementation

****************************************************/

#include <stdio.h>
#include <math.h>

int main(void) {

	double down_payment, purchase_price, annual_interest_rate, num_payments, principal, monthly_interest_rate, monthly_payment, x, y, z;

	printf("What is the purchase price of the car?\n");
	scanf("%lf", &purchase_price);

	printf("What is the down payment?\n");
	scanf("%lf", &down_payment);

	printf("What is the annual interest rate?\n");
	scanf("%lf", &annual_interest_rate);

	printf("How many payments will there be?\n");
	scanf("%lf", &num_payments);

	principal = ( purchase_price - down_payment );

	monthly_interest_rate = annual_interest_rate / 1200;

	x = 1 + monthly_interest_rate;

	y = -num_payments;

	z = pow(x, y);

	monthly_payment = (monthly_interest_rate * principal) / (1 - z) ;

	printf("The amount borrowed will be $%.2lf\n", principal);
	printf("The monthly payment will be $%.2lf\n", monthly_payment);

	return 0;

}