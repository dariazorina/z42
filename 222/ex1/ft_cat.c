/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 19:58:39 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/10 13:53:27 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_read(char *program, char *filename)
{
	char	buffer[100];
	int		file;
	int		readcount;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_putstr(basename(program));
		write(2, ": ", 2);
		ft_putstr(filename);
		write(2, ": ", 2);
		ft_putstr(strerror(errno));
		write(2, "\n", 1);
		return (1);
	}
	readcount = read(file, buffer, 100);
	while (readcount > 0)
	{
		write(1, buffer, readcount);
		readcount = read(file, buffer, 100);
	}
	close(file);
	return (0);
}

int	main(int ac, char **av)
{
	char	buffer[1];
	int		i;
	int		error;

	error = 0;
	i = 1;
	if (ac < 2)
	{
		while (i)
		{
			i = read(0, buffer, 1);
			write(1, buffer, i);
		}
	}
	else
	{
		while (i < ac)
		{
			error = error || ft_read(av[0], av[i]);
			i++;
		}
	}
	return (error);
}
