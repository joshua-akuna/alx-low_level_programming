#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * main - The program's main entry point.
 *
 * Description: 'The program generates a random number
 * for variable n and prints its last digit check for the conditions:
 * Last digit of n is greater than 5
 * Less than 6 or
 * and is 0
 *
 * Return: Always 0 (if successfully run)
 */

int main(void)
{
	/*declaring a variable n*/
	int n;
	int res;
	char f1[50];
	char f2[50];
	char f3[50];

	/*Initializing the random number generator*/
	srand(time(0));
	/*Generating a random integer for n*/
	n = rand() - RAND_MAX / 2;

	/*Get the last digit of the variable n*/
	res = n % 10;
	res = abs(res);
	
	strcpy(f1, "and is greater than 5");
	strcpy(f2, "and is 0");
	strcpy(f3, "and is less than 6 and not 0");

	/*Checks for the following conditions*/
	if (res > 5)
		printf("Last digit of %d is %d %s\n", n,  res, f1);
	if (res == 0)
		printf("Last digit of %d is %d %s\n", n, res, f2);
	else
		printf("Last digit of %d is %d %s\n", n, res, f3);

	/*return 0*/
	return (0);
}
