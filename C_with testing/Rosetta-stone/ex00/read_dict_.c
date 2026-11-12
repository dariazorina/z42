/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:34:02 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 11:41:49 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>  // open, O_RDONLY
#include <stdlib.h> // malloc, free, NULL
#include <unistd.h> // read, close, ssize_t

char	*ft_read_file(const char *path)
{
	int		fd;
	char	chunk[1024];
	ssize_t	n;
	size_t	file_size;
	size_t	file_pointer;
	char	*buffer;

	file_size = 0;
	file_pointer = 0;
	fd = open(path, O_RDONLY);
	while (1 == 1)
	{
		n = read(fd, chunk, sizeof(chunk));
		if (n == -1)
		{
			close(fd);
			return (NULL);
		}
		else if (n == 0)
		{
			close(fd);
			break ;
		}
		else
		{
			file_size += n;
		}
	}
	buffer = malloc(file_size + 1);
	if (buffer == NULL)
	{
		return (NULL);
	}
	if (file_size > 0)
	{
		fd = open(path, O_RDONLY);
		while (1 == 1)
		{
			n = read(fd, buffer + file_pointer, file_size - file_pointer);
			if (n == -1)
			{
				close(fd);
				return (NULL);
			}
			else if (n == 0)
			{
				close(fd);
				break ;
			}
			else
			{
				file_pointer += (size_t)n;
			}
		}
		close(fd);
	}
	buffer[file_pointer] = '\0';
	return (buffer);
}
