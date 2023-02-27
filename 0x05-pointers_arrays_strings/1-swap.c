/**
 * swap_int- swap the values of two int pointers.
 * @a: first int pointer parameter.
 * @b: second int pointer parameter.
 */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
