#include "regex.h"
/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int i, j, flag;
	char s, p;

	i = 0;
	j = i;
	flag = 0;
	while (str[j])
	{
		s = str[j];
		p = pattern[i];
		if (s == p || p == '.')
		{
			i++;
			j++;
		}
		if (pattern[i + 1] == '*' && p != '*')
		{
			flag = 1;
		}
		if (pattern[i - 1] == '*' && p != '*')
		{
			flag = 0;

		}
		if (p == '*')
			i++;
		if (s != p)
		{
			if (flag == 0)
				return (0);

		}
		j++;
	}
	return (1);
}

