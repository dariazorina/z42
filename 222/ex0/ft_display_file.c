/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:25:58 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/10 11:43:57 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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

int	ft_read(char *filename)
{
	char	buffer[100];
	int		file;
	int		readcount;

	file = open(filename, O_RDONLY);
	if (file == -1)
	{
		ft_putstr("Cannot read file.\n");
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
	int	read;

	if (ac < 2)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	else if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
	read = ft_read(av[1]);
	return (read);
}
