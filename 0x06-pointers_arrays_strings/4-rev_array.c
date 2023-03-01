/**
 * reverse_array- reverse the contents of an array of integers.
 * @a: an int pointer pointing to an array.
 * @n: the number of consecutive elements in th array to reverse.
 */

void reverse_array(int *a, int n)
{
	int i, half_len, temp;

	i = 0;
	half_len = (n / 2);

	while (i < half_len)
	{
		temp = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = temp;

		i++;
	}
}
