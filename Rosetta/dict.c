/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 10:18:17 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 11:43:35 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include <fcntl.h>  // open, O_RDONLY
#include <stdlib.h> // malloc, free, NULL
#include <unistd.h> // read, close, ssize_t

size_t	count_lines(const char *buffer)
{
	size_t	count;

	count = 1;
	while (*buffer)
	{
		if (*buffer == '\n')
			count++;
		buffer++;
	}
	return (count);
}

char	*get_line(char **buffer)
{
	char	*line;
	char	*end;

	line = *buffer;
	end = line;
	while (*end && *end != '\n')
		end++;
	*buffer = end;
	if (*end == '\n')
	{
		*end = '\0';
		*buffer = end + 1;
	}
	return (line);
}

char	*parse_value(char *value)
{
	char	*end;

	while (*value == ' ')
		value++;
	end = value;
	while (*end)
	{
		if (*end < ' ' || *end > '~')
			return (NULL);
		end++;
	}
	while (end > value && *(end - 1) == ' ')
		end--;
	*end = '\0';
	if (end == value)
		return (NULL);
	return (value);
}

int	parse_entry(char *line, t_entry *entry)
{
	char	*key_end;
	char	*colon;

	key_end = line;
	while (*key_end >= '0' && *key_end <= '9')
		key_end++;
	if (key_end == line)
		return (0);
	colon = key_end;
	while (*colon == ' ')
		colon++;
	if (*colon != ':')
		return (0);
	entry->value = parse_value(colon + 1);
	if (entry->value == NULL)
		return (0);
	*key_end = '\0';
	entry->key = line;
	return (1);
}

t_entry	*ft_parse_dict(char *buffer, size_t *count)
{
	t_entry	*dict;
	char	*line;
	size_t	i;

	*count = 0;
	if (buffer == NULL)
		return (NULL);
	dict = malloc(count_lines(buffer) * sizeof(*dict));
	if (dict == NULL)
		return (NULL);
	i = 0;
	while (*buffer)
	{
		line = get_line(&buffer);
		if (*line && !parse_entry(line, &dict[i]))
		{
			free(dict);
			return (NULL);
		}
		if (*line)
			i++;
	}
	*count = i;
	return (dict);
}
