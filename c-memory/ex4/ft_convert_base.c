/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 13:12:38 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/04 20:42:06 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_base_check(char *base);
int		ft_strlen(char *str);

int	ft_atoi(char *nbr, char *base)
{
	long	number;
	int		i;
	int		len;

	len = ft_strlen(base);
	i = 0;
	number = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i] != '\0')
	{
		number = number * len + (nbr[i] - '0');
		i++;
	}
	if (nbr[0] == '-')
		number = -number;
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
	bool	negative;

	if (ft_base_check(base_from) || ft_base_check(base_to))
		return (NULL);
	number = ft_atoi(nbr, base_from);
	negative = (number < 0);
	if (negative)
		number = -number;
	res_len = ft_res_length(number, base_to);
	if (res_len == 0)
		res_len = 1;
	res = malloc(res_len + negative + 1);
	if (res == NULL)
		return (NULL);
	if (negative)
		res[0] = '-';
	ft_fill_res(res + negative, res_len, number, base_to);
	return (res);
}
