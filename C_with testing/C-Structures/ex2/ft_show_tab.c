/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 13:57:42 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/12 14:39:41 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_size(int nb)
{
	char	digit;

	if (nb >= 10)
		ft_print_size(nb / 10);
	digit = '0' + nb % 10;
	write(1, &digit, 1);
}

void	ft_print_str(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str != NULL)
	{
		ft_print_str(par->str);
		ft_print_size(par->size);
		write(1, "\n", 1);
		ft_print_str(par->copy);
		par++;
	}
}
