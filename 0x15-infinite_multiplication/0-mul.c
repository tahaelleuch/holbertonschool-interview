#include <stdlib.h>
#include <unistd.h>


/**
 * long_multiplication - multiplicat two strings of digits
 * @num_a: first number
 * @num_b: second number
 * @first: first number length
 * @scnd: second number length
 * Return: 98 on error or 0 on success
 */
int long_multiplication(char num_a[], char num_b[], long int first, long int scnd)
{
	int mid;
	long int a, b, r;
	char *res, *one;

	res = malloc(first + scnd + 1);
	if (res == NULL)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	for (a = 0; a < first + scnd + 3; a++)
		res[a] = 0;
	for (a = first - 1; a >= 0; a--)
		for (b = scnd - 1; b >= 0; b--)
		{
			res[a + b + 1] += ((num_a[a] - '0') *
								  (num_b[b] - '0'));
			for (r = a + b + 1; res[r] > 9;
				 r--)
			{
				mid = res[r] / 10;
				res[r - 1] += mid;
				res[r] %= 10;
			}
		}
	for (a = first + scnd - 1; a >= 0; a--)
		res[a] += '0';
	for (one = res; *one == '0' && one[1] != 0; one++)
		first--;
	first += scnd;
	write(1, one, first);
	write(1, "\n", 1);
	free(res);

	return (0);
}


/**
 * main -  program that multiplies two positive numbers
 * @argc: num of arguments
 * @argv: arguments list
 * Return: status of 98 if error, 0 if success
 */
int main(int argc, char *argv[])
{
	long int first, scnd;
	char *a, *b;

	if (argc != 3)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	first = 0;
	for (a = argv[1]; *a != 0; a++, first++)
		if (*a < '0' || *a > '9')
		{
			write(1, "Error\n", 6);
			return (98);
		}
	scnd = 0;
	for (b = argv[2]; *b != 0; b++, scnd++)
		if (*b < '0' || *b > '9')
		{
			write(1, "Error\n", 6);
			return (98);
		}
	if (first == 0 || scnd == 0)
	{
		write(1, "Error\n", 6);
		return (98);
	}
	for (a = argv[1]; *a == '0' && a[1] != 0; first--)
		a++;
	for (b = argv[2]; *b == '0' && b[1] != 0; scnd--)
		b++;

	return (long_multiplication(a, b, first, scnd));
}
