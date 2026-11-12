/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:43:01 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/12 14:56:39 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str);
/*
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

void	ft_copy_str(char *str_dest, char *str_source)
{
	int	i;

	i = 0;
	while (str_source[i])
	{
		str_dest[i] = str_source[i];
		i++;
	}
	str_dest[i] = '\0';
}

t_stock_str	*ft_free_memory(t_stock_str *res, int i)
{
	while (i > 0)
	{
		i--;
		free(res[i].copy);
	}
	free(res);
	return (NULL);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*res;

	i = 0;
	res = malloc(sizeof(*res) * ((size_t)ac + 1));
	if (res == NULL)
		return (NULL);
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = malloc((size_t)res[i].size + 1);
		if (res[i].copy == NULL)
			return (ft_free_memory(res, i));
		ft_copy_str(res[i].copy, res[i].str);
		i++;
	}
	res[i].str = NULL;
	return (res);
}
