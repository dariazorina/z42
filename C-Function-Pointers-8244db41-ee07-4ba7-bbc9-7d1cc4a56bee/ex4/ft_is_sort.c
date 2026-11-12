/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 13:54:59 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/11 18:29:40 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	dir;
	int	cur_dir;

	i = 0;
	while (i < length - 1)
	{
		dir = f(tab[i], tab[i + 1]);
		if (dir != 0)
		{
			while (i < length - 2)
			{
				i++;
				cur_dir = f(tab[i], tab[i + 1]);
				if ((dir < 0 && cur_dir > 0) || (dir > 0 && cur_dir < 0))
					return (0);
			}
		}
		i++;
	}
	return (1);
}

/*#include <stdio.h>

int	ft_sort(int a, int b)
{
	int	res;
	int	i;
	int	dir;
	int	cur_dir;

	if (a < b)
		res = -1;
	else if (a == b)
		res = 0;
	else
		res = 1;
	return (res);
}*/
/*int	main(void)
{
	int	tab[4] = {1, 2, 3, 0};
	int	res;

	res = ft_is_sort(tab, 4, ft_sort);
	printf("%d\n", res);
	return (0);
}*/
