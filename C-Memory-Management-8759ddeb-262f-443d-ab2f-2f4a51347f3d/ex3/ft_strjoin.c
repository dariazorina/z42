/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:47:09 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/09 11:23:43 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_copy(char *res_str, char *source_str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(res_str);
	while (source_str[i] != '\0')
	{
		res_str[len + i] = source_str[i];
		i++;
	}
	res_str[len + i] = '\0';
}

size_t	ft_joinsize(int size, char **strs, char *sep)
{
	size_t	total;
	int		index;

	total = 0;
	if (size > 1)
		total = (size - 1) * ft_strlen(sep);
	index = 0;
	while (index < size)
	{
		total += ft_strlen(strs[index]);
		index++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res_str;
	int		index;

	if (size == 0)
		res_str = malloc(1);
	res_str = malloc(ft_joinsize(size, strs, sep) + 1);
	if (res_str == NULL)
		return (NULL);
	res_str[0] = '\0';
	index = 0;
	while (index < size)
	{
		ft_copy(res_str, strs[index]);
		if (index < size - 1)
			ft_copy(res_str, sep);
		index++;
	}
	return (res_str);
}
