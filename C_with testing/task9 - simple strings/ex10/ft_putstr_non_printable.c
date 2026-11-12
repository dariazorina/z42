/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:01:29 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/28 15:22:22 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_gethex(int value)
{
	char	c;

	if (value < 10)
		c = value + '0';
	else
		c = value - 10 + 'a';
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	index;
	int	c;

	index = 0;
	while (str[index] != '\0')
	{
		c = (unsigned char)str[index];
		if (c >= 32 && c <= 126)
			write(1, &str[index], 1);
		else
		{
			write(1, "\\", 1);
			ft_gethex(c / 16);
			ft_gethex(c % 16);
		}
		index++;
	}
}
