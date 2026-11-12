/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 17:05:22 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/26 18:23:28 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i1;
	int	i2;
	int	temp;

	i1 = 0;
	while (i1 < size - 1)
	{
		i2 = 0;
		while (i2 < size - 1 - i1)
		{
			if (tab[i2] > tab[i2 + 1])
			{
				temp = tab[i2];
				tab[i2] = tab[i2 + 1];
				tab[i2 + 1] = temp;
			}
			i2++;
		}
		i1++;
	}
}
