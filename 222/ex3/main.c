/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:12:32 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/11 17:43:38 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft.h"
#include <fcntl.h>

int	ft_display_file(t_file file, t_file *remain, int total)
{
	int	i;

	i = 0;
	while (i < 16 - remain->size && i < file.size)
	{
		remain->content[remain->size + i] = file.content[i];
		i++;
	}
	remain->size += i;
	if (remain->size == 16)
	{
		total = ft_display_line(remain->content, total, 16);
		remain->size = 0;
		while (i + 16 < file.size)
		{
			total = ft_display_line(&file.content[i], total, 16);
			i += 16;
		}
		while (i + remain->size < file.size)
		{
			remain->content[remain->size] = file.content[i + remain->size];
			remain->size++;
		}
	}
	return (total);
}

void	ft_display(t_file *files, int size)
{
	t_file	remain;
	int		i;
	int		total;

	i = 0;
	remain.size = 0;
	total = 0;
	remain.content = malloc(16);
	while (i < size)
	{
		if (files[i].size < 0)
			ft_display_error(files[i].name);
		else
			total = ft_display_file(files[i], &remain, total);
		i++;
	}
	if (remain.size > 0)
		total = ft_display_line(&remain.content[0], total, remain.size);
	if (total > 0)
	{
		ft_display_size(total);
		write(1, "\n", 1);
	}
}

char	*ft_add_char(char *old, int total, char c)
{
	char	*new_b;
	int		i;

	i = 0;
	new_b = malloc(total + 1);
	while (i < total)
	{
		new_b[i] = old[i];
		i++;
	}
	new_b[total] = c;
	return (new_b);
}

t_file	ft_handle_stdin(void)
{
	t_file	file;
	char	buffer[1];
	char	*content;
	int		rc;
	int		total;

	rc = 1;
	total = 0;
	content = "";
	while (rc > 0)
	{
		rc = read(0, buffer, 1);
		if (rc > 0)
		{
			content = ft_add_char(content, total, buffer[0]);
			total++;
		}
	}
	file.size = total;
	file.content = content;
	return (file);
}

int	main(int ac, char **av)
{
	t_file	*files;
	int		i;
	int		error;

	error = 0;
	files = malloc((ac - 1) * sizeof(t_file));
	i = 2;
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'C')
	{
		files[0] = ft_handle_stdin();
		ft_display(files, 1);
	}
	else if (ac > 2 && av[1][0] == '-' && av[1][1] == 'C')
	{
		while (i < ac)
		{
			files[i - 2] = ft_add_file(av[i]);
			error = error || (files[i - 2].size < 0);
			i++;
		}
		ft_display(files, ac - 2);
	}
	return (error);
}
