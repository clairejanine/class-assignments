/****************************************************
Program name:	stats.c
Author:			Claire Vannette	010971984
Date submitted: 4/11/16
Class:			CSCI 112
Instructor:		Chris Slater
Compiler:		Visual Studio 2015
OS:				Windows 10
Description:	Calculate various parameters for a collection of test scores
Input files:	None
Output files:	csis.txt
****************************************************/

/****************************************************
Analysis
	Inputs:			None
	Outputs:		Terminal, csis.txt
	Constraints:	Initialize the array with grades when declared, each section of the lab should be its own function, use given data in order it was given, main is first function
	Formulas:		
****************************************************/

/****************************************************
Design
	1. Create an array with the given scores and print 5 per line.
		1.1 Declare the array with the given scores.
		1.2 Print scores 5 per line.
			1.2.1 Create function printArray()
			1.2.1 Use for loop to print each item followed by a space, or followed by a newline every fifth
	2. Sort the scores in ascending order and print 5 per line.
		2.1 Sort the scores in ascending order.
			2.1.1 Create function sortAndPrintArray() 
			2.1.2 Create function compare()
			2.1.3 Use qsort()
		2.2 Print scores 5 per line.
			2.2.1 Run printArray()
	3. Calculate and print frequency table (values in decreasing order).
		3.1 Calculate frequency.
			3.1.1 Create new array with 101 entries, each initialized to 0
			3.1.2 Go through scores array and increment the array entry corresponding to each score whenever it appears.
		3.2 Print frequency table
			3.2.1 Print header
			3.2.2 If value in array entry is not zero, print array entry number and contents
	4. Calculate and print percentage passing and failing to the nearest tenth.
		4.1 Calculate passing and failing percentages (passing is 60%+).
			4.1.1 Create passFail() function
			4.1.2 Create pass and fail variables
			4.1.3 Go through scores array and increment fail for scores less than 60, and pass for scores greater than or equal to 60
			4.1.4 Divide size by pass and fail counts to get percentages
		4.2 Print percentages to tenth.
	5. Calculate and print the mean to the nearest tenth.
		5.1 Calculate the mean.
			5.1.1 Sum the scores array
			5.1.2 Divide by size
		5.2 Print the mean to tenth.
	6. Find and print the mode.
		6.1 Find the mode.
			6.1.1 Loop through frequency to look for the largest value
			6.1.2 Set variable mode to that array number
		6.2 Print the mode.
	7. Find and print the median. 
		7.1 Find the median.
			7.1.1 Check if size is odd or even
			7.1.2 If size is odd, assign the middle array element to variable median
			7.1.3 If size is even, find the mean of the middle two array elements
		7.2 Print the median.
****************************************************/

/****************************************************
Testing

****************************************************/

/****************************************************
Implementation

****************************************************/

#include <stdio.h>
#include <stdlib.h>

FILE *fp;

void printArray(int scores[], int size);
void sortAndPrintArray(int scores[], int size);
int compare(const void *p, const void *q);
void frequencyTable(int scores[], int frequency[], int size);
void passFail(int scores[], int size);
void meanScore(int scores[], int size);
void modeScore(int frequency[]);
void medianScore(int scores[], int size);

int main(void) {

	fp = fopen("csis.txt", "w");

	int scores[30] = { 90, 85, 100, 50, 50, 85, 60, 70, 55, 55, 80, 95, 70, 60, 95,
	80, 100, 75, 70, 95, 90, 90, 70, 95, 50, 65, 85, 95, 100, 65 }; // Declare the array with the given scores.
	int size = 30; 
	static int frequency[101]; // Declare array for frequency table

	printf("Unsorted Scores:\n"); // Print scores 5 per line.
	fprintf(fp, "Unsorted Scores:\n");
	printArray(scores, size);

	printf("\nSorted Scores:\n"); // Sort the scores in ascending order and print 5 per line.
	fprintf(fp, "\nSorted Scores:\n");
	sortAndPrintArray(scores, size);

	printf("\nFrequency Table:\n"); // Calculate and print frequency table
	fprintf(fp, "\nFrequency Table:\n");
	frequencyTable(scores, frequency, size);

	printf("\nPass/Fail Percentages:\n"); // Calculate passing and failing percentages
	fprintf(fp, "\nPass/Fail Percentages:\n");
	passFail(scores, size);

	printf("\nMean of Scores:\n"); // Calculate and print the mean to the nearest tenth
	fprintf(fp, "\nMean of Scores:\n");
	meanScore(scores, size);

	printf("\nMode of Scores:\n"); // Calculate and print the mode
	fprintf(fp, "\nMode of Scores:\n");
	modeScore(frequency);

	printf("\nMedian of Scores:\n"); // Calculate and print the median
	fprintf(fp, "\nMedian of Scores:\n");
	medianScore(scores, size);

	fclose(fp);

	return 0;
}

void printArray(int scores[], int size) {
	int i;
	for (i = 0; i < size; i++) { // Use for loop to print each item followed by a space, or followed by a newline every fifth
		printf("%5d", scores[i]);
		fprintf(fp, "%5d", scores[i]);
		if ((i + 1) % 5 == 0) {
			printf("%c", '\n');
			fprintf(fp, "%c", '\n');
		}
		else {
			printf("%c", ' ');
			fprintf(fp, "%c", ' ');
		}
	}
}

void sortAndPrintArray(int scores[], int size) {
	qsort(scores, size, sizeof(int), compare); // Use qsort
	printArray(scores, size); // Print 5 per line
}

int compare(const void *p, const void *q) { // Create compare function for qsort
	if (*(int *)p < *(int *)q) {
		return -1;
	}
	return *(int *)p > *(int *)q;
}

void frequencyTable(int scores[], int frequency[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		frequency[(scores[i])]++; // loop through the scores array, and for each value, increment the corresponding entry in the frequency array
	}
	printf("score\t\tfrequency\n"); // print header
	fprintf(fp, "score\t\tfrequency\n");
	printf("_____\t\t_________\n");
	fprintf(fp, "_____\t\t_________\n");
	for (i = 101; i > -1; i--) {
		if (frequency[i] != 0) {
			printf("%5d\t\t%5d\n", i, frequency[i]); // only print if the entry in frequency array is not zero
			fprintf(fp, "%5d\t\t%5d\n", i, frequency[i]);
		}
	}
}

void passFail(int scores[], int size) {
	int pass = 0, fail = 0, i = 0;
	double passPct = 0, failPct = 0;
	for (i = 0; i < size; i++) {
		if (scores[i] < 60) { // increment fail with each score below 60
			fail++;
		}
		else { // increment pass with each score 60 or above
			pass++;
		}
	}
	passPct = (double) pass / size * 100; // calculate pass percentage
	failPct = (double) fail / size * 100; // calculate fail percentage
	printf("%.1lf percent of students passed, and %.1lf percent of students failed.\n", passPct, failPct);
	fprintf(fp, "%.1lf percent of students passed, and %.1lf percent of students failed.\n", passPct, failPct);
}

void meanScore(int scores[], int size) {
	int i = 0, sum = 0;
	double mean = 0;
	for (i = 0; i < size; i++) {
		sum += scores[i]; // add up all values in score array 
	}
	mean = (double) sum / size; // divide the sum by the number of entries in the score array
	printf("The mean of the scores is %.1lf.\n", mean);
	fprintf(fp, "The mean of the scores is %.1lf.\n", mean);
}

void modeScore(int frequency[]) {
	int biggest = 0, mode = 0, i = 0;
	for (i = 0; i < 101; i++) {
		if (frequency[i] > biggest) { // look for the largest value in the frequency array
			biggest = frequency[i];
			mode = i; // set mode equal to number of that array entry, which corresponds to that score
		}
	}
	printf("The mode score is %d.\n", mode);
	fprintf(fp, "The mode score is %d.\n", mode);
} // nb: does not account for the possibility of multiple modes

void medianScore(int scores[], int size) {
	int midpoint = 0;
	double median = 0;
	if (size % 2 == 1) { // determine if size is odd or even
		midpoint = size / 2; // find the midpoint if odd
		median = scores[midpoint];
	}
	else {
		midpoint = size / 2; // find the array entry just above the midpoint
		median = (scores[midpoint] + scores[midpoint - 1]) / 2; // average the value just above and below the midpoint
	}
	printf("The median score is %.1lf.\n", median);
	fprintf(fp, "The median score is %.1lf.\n", median);
}

