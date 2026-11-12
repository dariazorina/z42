/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 12:48:39 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/10 13:53:42 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>

int	ft_numeric(char *v)
{
	int	i;

	i = 0;
	while (v[i] != '\0')
		if (!(v[i] >= '0' && v[i] <= '9'))
			return (0);
		else
			i++;
	return (1);
}*/
int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		else
			i++;
	}
	return (0);
}

/*int	main(void)
{
	char	*tab[3];
	int	res;

	tab[0] = "wer";
	tab[1] = "frty";
	tab[2] = NULL;

	res = ft_any(tab, ft_numeric);
	printf("%d\n", res);

	return (0);
}*/
