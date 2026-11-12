/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numtoword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnorouzi <rnorouzi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 13:48:57 by rnorouzi          #+#    #+#             */
/*   Updated: 2026/11/08 14:33:42 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}			t_entry;

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

int	put_temp(char *temp, int m, t_entry *dict, int count, int *j)
{
	char	temp_1[2];
	char	temp_2[3];
	char	temp_3[2];

	if (m == 3 && temp[0] != '0')
	{
		temp_1[0] = temp[0];
		temp_1[1] = '\0';
		if (find_print(temp_1, dict, count, j) == 0)
			return (0);
		if (find_print("100", dict, count, j) == 0)
			return (0);
	}
	if (m >= 2 && temp[m - 2] == '1')
	{
		temp_2[0] = temp[m - 2];
		temp_2[1] = temp[m - 1];
		temp_2[2] = '\0';
		if (find_print(temp_2, dict, count, j) == 0)
			return (0);
	}
	else if (m >= 2 && temp[m - 2] >= '2')
	{
		temp_2[0] = temp[m - 2];
		temp_2[1] = '0';
		temp_2[2] = '\0';
		if (find_print(temp_2, dict, count, j) == 0)
			return (0);
	}
	if ((m == 1 && temp[0] == '0') || (temp[m - 1] != '0' && (m == 1 || temp[m
				- 2] != '1')))
	{
		temp_3[0] = temp[m - 1];
		temp_3[1] = '\0';
		if (find_print(temp_3, dict, count, j) == 0)
			return (0);
	}
	return (1);
}

int	putnbr(char *temp, int ns, int m, t_entry *dict, int count, int *j)
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
	if (put_temp(temp, m, dict, count, j) == 0)
	{
		free(d);
		return (0);
	}
	i = 0;
	while (temp[i] == '0')
		i++;
	if (ns > 0 && temp[i] != '\0')
	{
		if (find_print(d, dict, count, j) == 0)
		{
			free(d);
			return (0);
		}
	}
	free(d);
	return (1);
}

int	numtoletter(char *num, t_entry *dict, int count)
{
	int		i;
	int		n;
	int		n_s;
	int		m;
	int		j;
	char	*temp;

	temp = malloc(4);
	if (!temp)
		return (0);
	while (num[0] == '0' && num[1] != '\0')
		num++;
	n = 0;
	while (num[n] != '\0')
		n++;
	if (n == 0)
	{
		free(temp);
		return (0);
	}
	n_s = (n - 1) - ((n - 1) % 3);
	m = 0;
	i = 0;
	j = 0;
	while (i < n)
	{
		temp[m] = num[i];
		m++;
		if ((n - i - 1) == n_s)
		{
			temp[m] = '\0';
			if (putnbr(temp, n_s, m, dict, count, &j) == 0)
			{
				free(temp);
				return (0);
			}
			m = 0;
			n_s = n_s - 3;
		}
		i++;
	}
	free(temp);
	write(1, "\n", 1);
	return (1);
}
