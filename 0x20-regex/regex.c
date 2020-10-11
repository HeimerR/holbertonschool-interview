#include "regex.h"
/**
 * regex_match - Checks whether a given pattern matches a given string
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: 1 if the pattern matches the string, or 0 if it doesn’t
 */
int regex_match(char const *str, char const *pattern)
{
	int ret;

	ret = strcmp(str, pattern);
	return (ret);
}
