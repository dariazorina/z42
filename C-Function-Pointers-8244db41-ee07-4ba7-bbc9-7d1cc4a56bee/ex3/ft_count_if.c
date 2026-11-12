/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:33:36 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/10 13:47:33 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_numeric(char *v)
{
		int     i;

		i = 0;
		while (v[i] != '\0')
				if (!(v[i] >= '0' && v[i] <= '9'))
						return (0);
				else
						i++;
		return (1);
}*/
int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	amount;

	i = 0;
	amount = 0;
	while (i < length)
	{
		if (f(tab[i]) != 0)
			amount++;
		i++;
	}
	return (amount);
}

/*int   main(void)
{
		char    *tab[3];
		int     res;

		tab[0] = "14567";
		tab[1] = "frty";
		tab[2] = "3444444442";

		res = ft_count_if(tab, 3, ft_numeric);
		printf("%d\n", res);

		return (0);
}*/
