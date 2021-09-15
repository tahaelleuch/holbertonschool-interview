#include "substring.h"


/**
 * find_substring - finds all the possible substrings within a given string.
 * @s: string to scan
 * @words: is the array of words
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the number
 * Return: an allocated array, storing each index in s
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int one = 0, two, c, *result, *temp, length, wlength;

	length = strlen(s);
	wlength = strlen(words[0]);
	result = (int *)malloc(length * sizeof(int));
	temp = (int *)malloc(nb_words * sizeof(int));

	while (one <= length - nb_words * wlength)
	{
		for (two = 0; two < nb_words; two++)
		{
			temp[two] = 0;
		}
		for (two = 0; two < nb_words; two++)
		{
			for (c = 0; c < nb_words; c++)
			{
				if (temp[c] == 0 && strncmp(s + one + two * wlength, words[c], wlength) == 0)
				{
					temp[c] = 1;
					break;
				}
			}
			if (c == nb_words)
			{
				break;
			}
		}
		if (two == nb_words)
		{
			result[(*n)++] = one;
		}
		one++;
	}
	free(temp);
	return (result);
}
