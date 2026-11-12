/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 11:10:56 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/10 16:24:59 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libgen.h>
#include <fcntl.h>
#include "ft.h"

void	add_char(char *result, char c, int tail)
{
	int	last;

	last = 0;
	while (result[last])
		last++;
	if (last == tail)
	{
		while (tail != 0)
		{
			result[last - tail] = result[last - tail + 1];
			tail--;
		}
		result[last - 1] = c;
	}
	else
		result[last] = c;
}

int	ft_read(char *result, char *filename, int tail)
{
	char	buffer[1];
	int		rc;
	int		file;

	file = 0;
	if (filename)
		file = open(filename, O_RDONLY);
	if (file < 0)
	{
		ft_error(filename);
		return (1);
	}
	else
	{
		rc = 1;
		while (rc > 0)
		{
			rc = read(file, buffer, 1);
			if (rc > 0)
				add_char(result, buffer[0], tail);
		}
		ft_putstr(result, 1);
	}
	close(file);
	return (0);
}

int	ft_display_header(char *filename, int showed)
{
	int	file;

	file = open(filename, O_RDONLY);
	if (file >= 0)
	{
		if (!showed)
			write(1, "==> ", 4);
		else
			write(1, "\n==> ", 5);
		ft_putstr(filename, 1);
		write(1, " <==\n", 5);
		return (1);
	}
	close(file);
	return (showed);
}

int	ft_display(char *filename, int tail)
{
	char	*result;
	int		i;

	result = malloc(tail + 1);
	i = 0;
	while (i < tail + 1)
	{
		result[i] = '\0';
		i++;
	}
	return (ft_read(result, filename, tail));
}

int	main(int ac, char **av)
{
	int	i;
	int	error;
	int	showed;

	error = 0;
	if (ac > 2 && av[1][0] == '-' && av[1][1] == 'c')
	{
		if (ft_atoi(av[2]) == -1)
			return (1);
		if (ac == 3)
			ft_display(NULL, ft_atoi(av[2]));
		else
		{
			i = 3;
			showed = 0;
			while (i < ac)
			{
				if (ac > 4)
					showed = ft_display_header(av[i], showed);
				error = error || ft_display(av[i], ft_atoi(av[2]));
				i++;
			}
		}
	}
	return (error);
}
