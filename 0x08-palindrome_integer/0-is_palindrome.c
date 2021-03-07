#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given integer is pal
 * @n: the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
*/
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;
	unsigned long mid = n;

	while (mid !=0)
	{
		rev = (rev * 10) + (mid % 10);
		mid = mid / 10;
	}
	if (rev == n)
		return (1);
	return (0);
}
