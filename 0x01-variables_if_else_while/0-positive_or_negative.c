#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - The program's entry point.
 *
 * Description: 'The program generates a random number n and prints
 * 	whether n is greater than, less than or equal to 0'
 *
 * Return: Always 0 (if successful)
 */

int main(void)
{
	/*declare an int variable n */
	int n;

	/*Initialize the random number generator */
	srand(time(0));
	/*Initialize n to a randomly generated number*/
	n = rand() - RAND_MAX/2;

	/*check if n is greater than, less than or equals to 0*/
	if (n > 0) printf("%d is positive\n", n);
	else if (n < 0) printf("%d is negative\n", n);
	else printf("%d is zero\n", n);

	/*returns 0 if no Exception occured*/
	return (0);
}
