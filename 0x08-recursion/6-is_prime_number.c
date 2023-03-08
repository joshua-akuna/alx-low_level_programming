int is_not_divisible(int n, int divisor);

/**
 * is_prime_number - determines if a number is a prime number.
 * @n: an int argument
 * Return: 1 if 'n' is a prime number else 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (is_not_divisible(n, 2));
} 

/**
 * isdivisible - determines if 'n' is divisible by "divisor" or a prime number.
 * @n: an int argument.
 * @divisor: a random int argument.
 * Return: 1 if 'n' is a prime number else 0.
 */
int is_not_divisible(int n, int divisor)
{
	if (divisor > (int)(n / 2))
		return (1);

	if (n % divisor == 0)
		return (0);

	return (is_not_divisible(n, divisor + 1));
}
