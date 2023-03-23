#ifndef _VARIADIC_FUNCTIONS_
#define _VARIADIC_FUNCTIONS_

#include <stdarg.h>
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct formatter - a struct for a specified character
 * and its corresponding pointer to a function.
 * @val: a character attribute.
 * @f: a pointer to a function.
 */
typedef struct formatter
{
	char val;
	void (*f)(va_list args);
} fmt;


#endif
