int sqrt_recursion(int n, int guess);

/**
 * _sqrt_recursion - calculates the square root of a number.
 * @n: an int argument whose square root to determine.
 * Return: -1 if 'n' has no natural square root else the calculated square root.
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (0);

	if (n == 1)
		return (1);

	return (sqrt_recursion(n, 2));
}

/**
 * sqrt_recursion - determines the square root of a number.
 * @n: an int argument whose square root to determine.
 * @guess: a random int argument which could be the natural square root of 'n'.
 * Return: -1 if 'n' has no natural square root else the calculated square root.
 */

int sqrt_recursion(int n, int guess)
{
	if (guess * guess == n)
		return (guess);

	if (guess * guess > n)
		return (-1);

	return (sqrt_recursion(n, guess + 1));
}
