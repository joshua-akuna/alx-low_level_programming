/**
 * factorial - calculates the factorial of a number.
 * @n: and int argument.
 * Return: Always factorial of 'n'.
 */
int factorial(int n)
{
	if (n <= 1)
		return (1);

	return (n * factorial(n - 1));
}
