#include <unistd.h>
#include <string.h>

/**
 * rand- gets an integer.
 * Return: returns an integer.
 */
int rand(void)
{
	static int counter = -1;

	counter++;
	switch (counter)
	{
		case 0:
		case 1:
			return (8);
		case 2:
			return (7);
		case 3:
			return (9);
		case 4:
			return (23);
		case 5:
			return (74);
	}
	return (counter * counter % 30000);
}
