/**
 * _pow_recursion- calculates the value of 'x' raised to the power of 'y'.
 * @x: an int argument.
 * @y: an int argument.
 * Return: -1 if 'y' is less than 0, else the value of 'x'
 * raised to the power of 'y'.
 */

int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);

	if (y == 0)
		return (1);

	if (x == 0)
		return (0);
	
	if (x == 1)
		return (1);
	
	return (x * _pow_recursion(x, y - 1));
}
