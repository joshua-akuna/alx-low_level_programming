#include <stdlib.h>
#include <stdio.h>
#include "main.h"

int _str_len(char *str);
char *times(char *num, char digit, int pad);
char *_add(char *res, char *cur);
void print_rev_str(char *str);
void _print(char *str);
char *zero_check(char *str);

/**
 * main- multiplies two positive integers.
 * @argc: number of input parameters.
 * @argv: an array of input parameters.
 * Return: return 0 if successful, else exit with status 89.
 */

int main(int argc, char *argv[])
{
	int i, j, len, pad = 0;
	char *res = 0, *cur = 0;

	if (argc != 3)
	{
		_print("Error");
		exit(98);
	}

	argv[2] = zero_check(argv[2]);
	argv[1] = zero_check(argv[1]);

	if (*argv[2] == '0' || *argv[1] == '0')
	{
		_print("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				_print("Error");
				exit(98);
			}
		}
	}
	len = _str_len(argv[1]);
	for (i = len - 1; argv[1][i]; i--)
	{
		cur = times(argv[2], argv[1][i], pad);
		res = _add(res, cur);
		pad++;
	}
	print_rev_str(res);
	free(res);
	return (0);
}

/**
 * _print - prints a string argument.
 * @str: pointer to a string srgument.
 */
void _print(char *str)
{
	int len, i;

	len = _str_len(str);

	for (i = 0; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * print_rev_str - prints a string argument in reverse.
 * @str: pointer to a string srgument.
 */
void print_rev_str(char *str)
{
	int len, i;

	len = _str_len(str);

	for (i = len - 1; i >= 0; i--)
		_putchar(str[i]);
	_putchar('\n');
}

/**
 * _add- adds up 2 string pointer filled with digits.
 * @res: a pointer to a string.
 * @cur: a pointer to a string.
 * Return: return the string which sums up both string arguments.
 */
char *_add(char *res, char *cur)
{
	unsigned int temp, i, j = 0, len_c;
	int flag = 0;
	char *sum;

	len_c = _str_len(cur);

	if (!res)
	{
		res = malloc(len_c);
		if (!res)
		{
			_print("Error");
			exit(89);
		}
	}

	sum = malloc(len_c + 3);

	for (i = 0; res[i] & cur[i]; i++)
	{
		temp = (res[i] - '0') + (cur[i] - '0') + flag;
		flag = 0;

		if (temp > 9)
		{
			temp -= 10;
			flag++;
		}

		sum[j++] = temp + '0';
	}
	for (; cur[i]; i++)
	{
		temp = (cur[i] - '0') + flag;
		flag = 0;

		if (temp > 9)
		{
			temp -= 10;
			flag++;
		}

		sum[j++] = temp + '0';
	}
	if (flag)
	{
		sum[j] = flag + '0';
		sum[j + 1] = 0;
	}
	else
	{
		sum[j] = 0;
	}

	free(res);
	free(cur);
	return (sum);
}

/**
 * _str_len - returs the length of the string "str"
 * @str: a pointer to a string.
 * Return: an integer.
 */
int _str_len(char *str)
{
	int i = 0, len = 0;

	while (str[i++])
		len++;
	return (len);
}
/**
 * times - return the product of number and a digit.
 * @num: a pointer to a string of integers.
 * @digit: a char with 1 digit.
 * @pad: and int for the number of zero padding for the return value.
 * Return: return the product of num and digit.
 */
char *times(char *num, char digit, int pad)
{
	int i, j = 0, len, n1, n2, flag = 0, ans = 0;
	char *res;

	n1 = digit - '0';
	len = _str_len(num);
	res = malloc(len + pad  + 3);

	for (i = 0; i < pad; i++)
		*(res + j++) = '0';

	for (i = len - 1; num[i]; i--)
	{
		n2 = num[i] - '0';
		ans = n1 * n2 + flag;
		flag = 0;

		if (ans > 9)
		{
			flag = ans / 10;
		}
		*(res + j++) = (ans % 10) + '0';
	}
	if (flag > 0)
		*(res + j++) = flag + '0';
	res[j] = '\0';

	return (res);
}
/**
 * zero_checker: checks if a string is equivalent to zero.
 * @str: a string argument.
 * Return: pointer to the first non zero digit.
 */
char *zero_check(char *str)
{
	while(*str == '0')
		if (*(str + 1) != 0)
			str++;
		else
			break;
	return (str);

}
