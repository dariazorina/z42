/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:34:02 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 15:02:41 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	get_file_size(const char *path, size_t *file_size)
{
	int		fd;
	char	chunk[1024];
	ssize_t	n;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	*file_size = 0;
	n = read(fd, chunk, sizeof(chunk));
	while (n > 0)
	{
		*file_size += (size_t)n;
		n = read(fd, chunk, sizeof(chunk));
	}
	close(fd);
	return (n == 0);
}

static int	fill_buffer(int fd, char *buffer, size_t file_size)
{
	size_t	offset;
	ssize_t	n;

	offset = 0;
	while (offset < file_size)
	{
		n = read(fd, buffer + offset, file_size - offset);
		if (n < 0)
			return (0);
		if (n == 0)
			break ;
		offset += (size_t)n;
	}
	buffer[offset] = '\0';
	return (1);
}

static char	*ft_reading(const char *path, size_t file_size)
{
	int		fd;
	int		ok;
	char	*buffer;

	buffer = malloc(file_size + 1);
	if (buffer == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		free(buffer);
		return (NULL);
	}
	ok = fill_buffer(fd, buffer, file_size);
	close(fd);
	if (!ok)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_read_file(const char *path)
{
	size_t	file_size;

	if (!get_file_size(path, &file_size))
		return (NULL);
	return (ft_reading(path, file_size));
}
