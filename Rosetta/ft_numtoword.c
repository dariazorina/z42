/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtoword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorouzi <rnorouzi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:38:56 by rnorouzi          #+#    #+#             */
/*   Updated: 2026/11/08 17:03:16 by rnorouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "dict.h"

int	find_print(char *temp, t_entry *dict, int count, int *j);
int	print_hundreds(char *temp, t_entry *dict, int count, int *j);
int	print_tens(char *temp, t_entry *dict, int count, int *j);
int	print_units(char *temp, t_entry *dict, int count, int *j);

int	putnbr(int ns, t_entry *dict, int count, int *j)
{
	int		i;
	char	*d;

	d = malloc(ns + 2);
	if (!d)
		return (0);
	d[0] = '1';
	i = 1;
	while (i <= ns)
	{
		d[i] = '0';
		i++;
	}
	d[ns + 1] = '\0';
	i = find_print(d, dict, count, j);
	free(d);
	return (i);
}

int	put_temp(char *temp, t_entry *dict, int count, int *j)
{
	if (print_hundreds(temp, dict, count, j) == 0)
		return (0);
	if (print_tens(temp, dict, count, j) == 0)
		return (0);
	if (print_units(temp, dict, count, j) == 0)
		return (0);
	return (1);
}

int	has_nonzero(char *temp)
{
	int	m;

	m = 0;
	while (temp[m] == '0')
		m++;
	if (temp[m] != '\0')
		return (1);
	return (0);
}

int	print_groups(char *num, int n, t_entry *dict, int count)
{
	char	temp[4];
	int		i;
	int		m;
	int		n_s;
	int		j;

	i = 0;
	m = 0;
	j = 0;
	n_s = (n - 1) - ((n - 1) % 3);
	while (i < n)
	{
		temp[m++] = num[i++];
		if (n - i != n_s)
			continue ;
		temp[m] = '\0';
		if (put_temp(temp, dict, count, &j) == 0
			|| (n_s > 0 && has_nonzero(temp)
				&& putnbr(n_s, dict, count, &j) == 0))
			return (0);
		m = 0;
		n_s -= 3;
	}
	return (1);
}

int	numtoletter(char *num, t_entry *dict, int count)
{
	int	n;

	while (num[0] == '0' && num[1] != '\0')
		num++;
	n = 0;
	while (num[n] != '\0')
		n++;
	if (n == 0)
		return (0);
	if (print_groups(num, n, dict, count) == 0)
		return (0);
	write(1, "\n", 1);
	return (1);
}
