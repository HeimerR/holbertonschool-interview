#include "regex.h"
#include <stdlib.h>
/**
 * regex_batch - Checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_batch(char const *str, char const *pattern)
{
	int status;
	char *bash;
	int l1, l2;

	l1 = strlen(str);
	l2 = strlen(pattern);
	bash = malloc(sizeof(char *) * (8 + l1 + l2));
	strcat(bash, "./regex_bash ");
	strcat(bash, str);
	strcat(bash, " ");
	strcat(bash, pattern);

	/*printf("%s\n", bash);*/
	status = system(bash);
	if (status != 0)
		return (1);
	return (status);
}

/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int j = 0;

	if (!strcmp(str, pattern))
		return (1);
	if (!strchr(pattern, '.') && !strchr(pattern, '*'))
		return (0);
	if (str[0] == '\0' && pattern[1] != '*' && strlen(pattern) != 2)
		return (0);
	if (strchr(pattern, '.') && !strchr(pattern, '*'))
	{
		while (str[j])
		{
			if (str[j] == pattern[j] ||  pattern[j] == '.')
				j++;
			else
				return (0);
		}
		return (1);
	}
	if (pattern[0] == '.' && pattern[1] == '*' && pattern[2] == '\n')
		return (1);
	if (!strchr(pattern, '.') && strchr(pattern, '*'))
		return (regex_batch(str, pattern));
	return (1);
}
