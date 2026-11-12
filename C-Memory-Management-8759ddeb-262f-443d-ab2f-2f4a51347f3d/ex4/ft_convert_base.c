/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:12:38 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 17:56:30 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_check(char *base);
int		ft_strlen(char *str);
int		ft_is_space(char c);
int		ft_base_digit(char c, char *base);

int	ft_atoi(char *nbr, char *base)
{
	long	number;
	int		len;
	int		sign;
	int		digit;

	len = ft_strlen(base);
	number = 0;
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign = -sign;
		nbr++;
	}
	digit = ft_base_digit(*nbr, base);
	while (digit >= 0)
	{
		number = number * len + digit;
		nbr++;
		digit = ft_base_digit(*nbr, base);
	}
	return (number * sign);
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

void	ft_fill_res(char *res, int res_len, long number, char *base_to)
{
	int	base_to_len;

	base_to_len = ft_strlen(base_to);
	res[res_len] = '\0';
	while (res_len > 0)
	{
		res_len--;
		res[res_len] = base_to[number % base_to_len];
		number = number / base_to_len;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*res;
	int		res_len;
	long	number;
	int		negative;

	if (ft_base_check(base_from) || ft_base_check(base_to))
		return (NULL);
	number = ft_atoi(nbr, base_from);
	negative = (number < 0);
	if (negative)
		number = -number;
	res_len = ft_res_length(number, base_to);
	if (res_len == 0)
		res_len = 1;
	res = ft_prepare_res(res_len + negative);
	if (res == NULL)
		return (NULL);
	if (negative)
		res[0] = '-';
	ft_fill_res(res + negative, res_len, number, base_to);
	return (res);
}
