/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:41:27 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/10 18:53:26 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"
#include <string.h>
#include <errno.h>

void	ft_putstr(char *str, int out)
{
	int	index;

	index = 0;
	while (str && str[index])
	{
		write(out, &str[index], 1);
		index++;
	}
}

void	ft_error(char *filename)
{
	ft_putstr("ft_tail: ", 2);
	ft_putstr(filename, 2);
	ft_putstr(": ", 2);
	ft_putstr(strerror(errno), 2);
	write(2, "\n", 1);
}
