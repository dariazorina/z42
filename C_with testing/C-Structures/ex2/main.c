/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:54:05 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/12 14:40:23 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int, char **);
void ft_show_tab(struct s_stock_str *);

int	main(int argc, char **argv)
{
	t_stock_str	*tab;
	int			i;

	tab = ft_strs_to_tab(argc - 1, argv + 1);
	if (tab == NULL)
		return (1);
//	i = 0;

//	while (tab[i].str != NULL){
	ft_show_tab(tab);
//		i++;
//	}

	i = 0;
	while (tab[i].str != NULL)
	{
		printf("size=%d str=\"%s\" copy=\"%s\"\n", tab[i].size, tab[i].str,
			tab[i].copy);
		free(tab[i].copy);
		i++;
	}

	free(tab);
	return (0);
}
