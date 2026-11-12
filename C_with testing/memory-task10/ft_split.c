/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:19 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/04 14:38:36 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_include_symbol(char symbol, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] != symbol)
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_words_amount(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (!ft_include_symbol(str[i], charset))
			if (str[i + 1] == '\0')
				words++;
		if (!ft_include_symbol(str[i], charset))
			if (ft_include_symbol(str[i + 1], charset))
				words++;
		i++;
	}
	return (words);
}

int	ft_prepare(char *str, char *charset)
{
	int		words;
	char	**set;

	if (ft_strlen(str) == 0)
		return (NULL);
	word = ft_words_amount(str, charset);
	if (word < 1)
		return (NULL);
	res = malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}

void ft_loop_body(int *j, char **res, int *word, int *k, int *i)
{
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		word;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = 0;
	word = 0;
	res = ft_prepare(str, charset);
	while (str[i] != '\0')
	{
		if ((!ft_include_symbol(str[i], charset) && str[i + 1] == '\0')
			|| (!ft_include_symbol(str[i], charset) && ft_include_symbol(str[i
					+ 1], charset)))
		{
			res[word] = malloc((j + 1) + 1);
			if (res[word] == NULL)
				return (NULL);
			k = 0;
			while (k < j + 1)
			{
				res[word][k] = str[i - j + k];
				k++;
			}
			res[word][k] = '\0';
			word++;
			i++;
			j = 0;
		}
		if (!ft_include_symbol(str[i], charset))
			j++;
		i++;
	}
	return (res);
}
