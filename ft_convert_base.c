/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:12:38 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/02 18:12:33 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *nbr, char *base)
{
	int	number;
	int	i;
	int	len;

	len = ft_strlen(base);
	i = 0;
	number = 0;
	while (nbr[i] != '\0')
	{
		number = number * len + (nbr[i] - '0');
		i++;
	}
	return (number);
}

int	ft_res_length(long number, char *base_to)
{
	int	base_len;
	int	len;

	base_len = ft_strlen(base_to);
	len = 1;
	if (number < 0)
	{
		len++;
		number = -number;
	}
	while (number >= base_len)
	{
		number = number / base_len;
		len++;
	}
	return (len);
}

char	*ft_prepare_res(int res_len)
{
	char	*res;

	res = malloc(res_len + 1);
	if (res == NULL)
		return (NULL);
	res[res_len] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		res_len;
	int		input_number_10;
	long	number;
	int		base_to_len;

	input_number_10 = ft_atoi(nbr, base_from);
	res_len = ft_res_length(input_number_10, base_to);
	res = ft_prepare_res(res_len);
	base_to_len = ft_strlen(base_to);
	number = input_number_10;
	if (number < 0)
	{
		number = -number;
		res[0] = '-';
	}
	while (res_len > 0)
	{
		res_len--;
		res[res_len] = base_to[number % base_to_len];
		number = number / base_to_len;
	}
	return (res);
}
