/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:29:51 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/09 17:46:27 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_number_error(char *str)
{
	ft_putstr("ft_tail: invalid number of bytes: '", 2);
	ft_putstr(str, 2);
	ft_putstr("'\n", 2);
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (ft_number_error(str));
	while (str[i])
	{
		if (!(str[i] <= '9' && str[i] >= '0'))
			return (ft_number_error(str));
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result);
}
