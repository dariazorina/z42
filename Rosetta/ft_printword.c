/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorouzi <rnorouzi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 16:33:58 by rnorouzi          #+#    #+#             */
/*   Updated: 2026/11/08 16:34:01 by rnorouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "dict.h"

int	find_print(char *temp, t_entry *dict, int count, int *j)
{
	int	i;
	int	n;

	i = 0;
	while (i < count)
	{
		n = 0;
		while (dict[i].key[n] && temp[n] && dict[i].key[n] == temp[n])
			n++;
		if (dict[i].key[n] == '\0' && temp[n] == '\0')
		{
			if (*j > 0)
				write(1, " ", 1);
			n = 0;
			while (dict[i].value[n] != '\0')
				n++;
			write(1, dict[i].value, n);
			*j = *j + 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	print_hundreds(char *temp, t_entry *dict, int count, int *j)
{
	char	temp_1[2];
	int		m;

	m = 0;
	while (temp[m] != '\0')
		m++;
	if (m == 3 && temp[0] != '0')
	{
		temp_1[0] = temp[0];
		temp_1[1] = '\0';
		if (find_print(temp_1, dict, count, j) == 0)
			return (0);
		if (find_print("100", dict, count, j) == 0)
			return (0);
	}
	return (1);
}

int	print_tens(char *temp, t_entry *dict, int count, int *j)
{
	char	temp_2[3];
	int		m;

	m = 0;
	while (temp[m] != '\0')
		m++;
	if (m >= 2 && temp[m - 2] == '1')
	{
		temp_2[0] = temp[m - 2];
		temp_2[1] = temp[m - 1];
		temp_2[2] = '\0';
		return (find_print(temp_2, dict, count, j));
	}
	else if (m >= 2 && temp[m - 2] >= '2')
	{
		temp_2[0] = temp[m - 2];
		temp_2[1] = '0';
		temp_2[2] = '\0';
		return (find_print(temp_2, dict, count, j));
	}
	return (1);
}

int	print_units(char *temp, t_entry *dict, int count, int *j)
{
	char	temp_3[2];
	int		m;

	m = 0;
	while (temp[m] != '\0')
		m++;
	if ((m == 1 && temp[0] == '0')
		|| (temp[m - 1] != '0' && (m == 1 || temp[m - 2] != '1')))
	{
		temp_3[0] = temp[m - 1];
		temp_3[1] = '\0';
		if (find_print(temp_3, dict, count, j) == 0)
			return (0);
	}
	return (1);
}
