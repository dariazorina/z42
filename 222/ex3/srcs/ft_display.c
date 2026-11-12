/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 12:43:39 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/11 12:26:47 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "ft.h"

int	ft_display_error(char *filename)
{
	ft_putstr("ft_hexdump: ", 2);
	ft_putstr(filename, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	write(2, "\n", 1);
	return (1);
}

void	ft_display_size(int nbr)
{
	char	*str;
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 7;
	str = malloc(9);
	while (i >= 0)
	{
		str[i] = hex[nbr % 16];
		nbr /= 16;
		i--;
	}
	str[8] = '\0';
	ft_putstr(str, 1);
	free(str);
}

int	ft_display_hex(char *str, int count)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < count)
	{
		if (i % 8 == 0)
			write(1, " ", 1);
		write(1, " ", 1);
		write(1, &hex[(unsigned char)str[i] / 16], 1);
		write(1, &hex[(unsigned char)str[i] % 16], 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 8 == 0)
			write(1, " ", 1);
		write(1, "   ", 3);
		i++;
	}
	return (count);
}

void	ft_display_str(char *str, int count)
{
	unsigned char	uc;
	int				i;

	i = 0;
	write(1, "  |", 3);
	while (i < count)
	{
		uc = (unsigned char)str[i];
		if (uc >= ' ' && uc <= '~')
			write(1, &uc, 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|\n", 2);
}

int	ft_display_line(char *line, int total, int count)
{
	ft_display_size(total);
	ft_display_hex(line, count);
	ft_display_str(line, count);
	return (total + count);
}
