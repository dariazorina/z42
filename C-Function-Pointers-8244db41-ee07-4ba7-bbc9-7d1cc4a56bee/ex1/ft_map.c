/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:28:35 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/10 13:51:02 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*#include <stdio.h>

int	ft_show_int(int nb)
{
	return (nb);
}
*/
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(int) * length);
	if (res == NULL)
		return (NULL);
	while (i < length)
	{
		res[i] = f(tab[i]);
		i++;
	}
	return (res);
}

/*int main()
{
		int     tab[] = {91, 24, 6};
		int *res = ft_map(tab, 3, ft_show_int);

		printf("%d %d %d\n", res[0], res[1], res[2]);
	free(res);
		return (0);
}*/
