/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:47:09 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/02 13:10:42 by dzorina          ###   ########.fr       */
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

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res_str;
	size_t	str_size;
	int		index;

	if (size == 0)
		return (malloc(1));
	str_size = (size - 1) * ft_strlen(sep);
	while (index < size)
	{
		str_size += ft_strlen(strs[index]);
		index++;
	}
	res_str = malloc(str_size + 1);
	if (res_str == NULL)
		return (NULL);
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
