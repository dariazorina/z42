/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:14:56 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/04 19:49:05 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_string_length(char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

void	ft_copy_string(char *destination, char *src)
{
	int	index;

	index = 0;
	while (src[index] != '\0')
	{
		destination[index] = src[index];
		index++;
	}
	destination[index] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*copy;

	copy = malloc(ft_string_length(str) + 1);
	if (copy == NULL)
		return (NULL);
	ft_copy_string(copy, str);
	return (copy);
}
