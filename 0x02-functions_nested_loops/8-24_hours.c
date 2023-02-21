#include "main.h"

/**
 * jack_bauer - prints every minute of the day starting
 * at "00:00" to "23:59".
 * Return: Has no return statement.
 */

void jack_bauer(void)
{
	int res, hr, min;

	for (hr = 0; hr < 24; hr++)
	{
		for (min = 0; min < 60; min++)
		{
			res = hr / 10;
			_putchar(res + '0');
			res = hr % 10;
			_putchar(res + '0');
			_putchar(':');
			res = min / 10;
			_putchar(res + '0');
			res = min % 10;
			_putchar(res + '0');
			_putchar('\n');
		}
	}
}
