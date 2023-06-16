#include "lists.h"
/**
 * main - keygen5
 * @argc: int argument
 * @argv: a string array
 */
int main(int argc, char *argv[])
{
	int size = 0, count, randh, temp;
	long seq[] = {
		0x3877445248432d41, 0x42394530534e6c37,
		0x4d6e706762695432, 0x74767a5835737956,
		0x2b554c59634a474f, 0x71786636576a6d34,
		0x723161513346655a, 0x6b756f494b646850
	};
	char *str = (char *)seq, *user = argv[1], *ptr, password[7];

	if (argc != 2)
		return (1);
	password[6] = 0;
	for (ptr = user; *ptr; ptr++)
		size++;
	password[0] = str[(size ^ 0x3b) & 0x3f];
	temp = 0;
	for (ptr = user; *ptr; ptr++)
		temp += *ptr;
	password[1] = str[(temp ^ 0x4f) & 0x3f];
	temp = 1;
	for (ptr = user; *ptr; ptr++)
		temp *= *ptr;
	password[2] = str[(temp ^ 0x55) & 0x3f];
	temp = *ptr;
	for (ptr = user; *ptr; ptr++)
		if (temp < *ptr)
			temp = *ptr;
	srand(temp ^ 0xe);
	password[3] = str[rand() & 0x3f];
	temp = 0;
	for (ptr = user; *ptr; ptr++)
		temp += *ptr * *ptr;
	password[4] = str[(temp ^ 0xef) & 0x3f];
	temp = *user;
	for (count = 0; count < temp; count++)
		randh = rand();
	password[5] = str[(randh ^ 0xe5) & 0x3f];
	printf("%s", password);
	return (0);
}
