/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 20:41:27 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/09 17:52:38 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

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
