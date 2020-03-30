#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - t checks whether or not a given
 * integer is a palindrome
 * @n: integer
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long i = 1, j = 10, n2 = n;

	if (n < 10)
		return (1);

	while (n >= 10)
	{
		i *= 10;
		n = n / 10;
	}

	while (i > 1)
	{
		if (n2 % j != n2 / i)
			return (0);
		n2 = (n2 % i) / 10;
		i /= 100;
	}
	return (1);
}
