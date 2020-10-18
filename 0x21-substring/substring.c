#include "substring.h"
/**
 * cmpfunc - compare tow values
 * @a: first value
 * @b: second value
 * Return: substraction
**/
int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}
/**
 * check - chek if all words are continous
 * @aux_indx: array with index for ever word
 * @wordlen: word size
 * @idx_len: aux_indx size
 * Return: index firt word or zero
**/
int check(int *aux_indx, int wordlen, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_indx[i + 1] - aux_indx[i]  != wordlen)
			return (0);
	}
	return (aux_indx[idx_len - 1]);
}
/**
 * search - search words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * Return: array with index for every word or NULL
**/
int *search(char const *s, char const **words, int nb_words)
{
	int *aux_indx, i, j;
	char *aux;
	int len;

	aux_indx = malloc((sizeof(int) * nb_words));
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
			return (NULL);
		len = (int)strlen(aux);
		/*printf("holas\n");*/
		/*printf("sublen: %d\n", len);*/
		for (j = 0; j < i; j++)
		{
			/*printf("len: %i, aux[%i]%i\n:", len, j, aux_indx[j]);*/
			if (len == aux_indx[j])
			{
				aux = strstr(s + strlen(s) - len + 1, words[i]);
				if (!aux)
					return (NULL);
				len = (int)strlen(aux);
				aux_indx[i] = len;
				continue;
			}

		}
		aux_indx[i] = len;
	}

	return (aux_indx);

}
/**
 * find_substring - search words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * @n: return size
 * Return: array with index for every word or NULL
 *
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indx, *aux_indx, wordlen, j, f_indx, diff, s_len;

	indx = malloc((sizeof(int)) * strlen(s));
	*n = 0;

	wordlen = strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		aux_indx = search(s, words, nb_words);
		if (!aux_indx && *n == 0)
			return (NULL);
		if (!aux_indx)
			break;
		qsort(aux_indx, nb_words, sizeof(int), cmpfunc);
		f_indx = check(aux_indx, wordlen, nb_words);
		if (f_indx)
		{
			diff = strlen(s) - f_indx + j;
			/*printf("diff %i\n", diff);*/
			if (diff != indx[*n - 1] || *n == 0)
			{
				indx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	*n = 0;
	return (NULL);
}
