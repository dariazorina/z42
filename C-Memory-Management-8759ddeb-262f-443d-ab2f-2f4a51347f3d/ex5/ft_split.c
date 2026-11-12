/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 16:12:19 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 18:13:29 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

char	**ft_prepare(char *str, char *charset)
{
	int		words;
	char	**res;

	words = ft_words_amount(str, charset);
	res = malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}

int	ft_loop_body(int *j, char **res, int *word, char *current)
{
	int	k;

	res[*word] = malloc(*j + 1 + 1);
	if (res[*word] == NULL)
		return (1);
	k = 0;
	while (k <= *j)
	{
		res[*word][k] = (current - *j)[k];
		k++;
	}
	res[*word][k] = '\0';
	(*word)++;
	*j = 0;
	return (0);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		word;
	char	**res;

	i = 0;
	j = 0;
	word = 0;
	res = ft_prepare(str, charset);
	if (res == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if ((!ft_include_symbol(str[i], charset)) && (str[i + 1] == '\0'
				|| ft_include_symbol(str[i + 1], charset)))
		{
			if (ft_loop_body(&j, res, &word, str + i))
				return (NULL);
		}
		else if (!ft_include_symbol(str[i], charset))
			j++;
		i++;
	}
	res[word] = NULL;
	return (res);
}
