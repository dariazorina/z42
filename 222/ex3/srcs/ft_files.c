/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 12:30:22 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/11 12:35:00 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"
#include <unistd.h>

char	*ft_content(char *filename, int size)
{
	char	*buffer;
	int		file;

	buffer = malloc(size);
	file = open(filename, O_RDONLY);
	read(file, buffer, size);
	close(file);
	return (buffer);
}

int	ft_size(char *filename)
{
	char	buffer[1];
	int		file;
	int		rc;
	int		size;

	size = 0;
	file = open(filename, O_RDONLY);
	if (file < 0)
		return (-1);
	rc = 1;
	while (rc > 0)
	{
		rc = read(file, buffer, 1);
		size += rc;
	}
	close(file);
	return (size);
}

t_file	ft_add_file(char *filename)
{
	t_file	file;

	file.name = filename;
	file.size = ft_size(filename);
	file.content = ft_content(filename, file.size);
	return (file);
}
