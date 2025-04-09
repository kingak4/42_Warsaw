#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int ft_len(char *s)
{
	int i  = 0;
	while (s[i])
		i++;
	return i;
}

// Usuwa spacje z początku, końca i zamienia wiele spacji na jedną
char *ft_space(char *s)
{
	int i = 0, 
	j = 0, 
	space = 0;
	int len = ft_len(s);
	char *res = malloc(len + 1);

	// Skip leading spaces
	while (s[i] == ' ' || s[i] == '\t')
		i++;

	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
		{
			if (!space)
				res[j++] = ' ';
			space = 1;
		}
		else
		{
			res[j++] = s[i];
			space = 0;
		}
		i++;
	}

	// Remove trailing space if present
	if (j > 0 && res[j - 1] == ' ')
		j--;

	res[j] = '\0';
	return res;
}

// Wyciąga resztę zdania bez pierwszego słowa
char *rem(char *s)
{
	int i = 0, j = 0, len = ft_len(s);
	char *s1;

	// Skip first word
	while (s[i] && s[i] != ' ')
		i++;

	// Skip space after first word
	while (s[i] == ' ')
		i++;

	s1 = malloc(len - i + 1);
	if (!s1)
		return NULL;

	while (s[i])
		s1[j++] = s[i++];

	s1[j] = '\0';
	return s1;
}

// Główna funkcja obracająca słowa
char *rostr(char *s)
{
	int i = 0;
	char first_word[100];
	char *s1 = ft_space(s);  // oczyszczenie spacji
	char *s2 = rem(s1);      // pozostała część bez pierwszego słowa

	// Skopiuj pierwsze słowo do bufora
	while (s1[i] && s1[i] != ' ')
	{
		first_word[i] = s1[i];
		i++;
	}
	first_word[i] = '\0';

	// Wypisz resztę + spację + pierwsze słowo
	if (s2[0] != '\0')
	{
		write(1, s2, ft_len(s2));
		write(1, " ", 1);
	}
	write(1, first_word, ft_len(first_word));
	write(1, "\n", 1);

	free(s1);
	free(s2);
	return NULL;
}

int main(int argc, char **argv)
{
	if (argc > 1)
		rostr(argv[1]);
	else
		write(1, "\n", 1);
	return 0;
}