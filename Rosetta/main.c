/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeli-wi <rgeli-wi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:48:13 by rgeli-wi          #+#    #+#             */
/*   Updated: 2026/11/08 16:27:16 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_read_file(const char *path);
t_entry	*ft_parse_dict(char *buffer, size_t *count);
int		numtoletter(char *num, t_entry *dict, int count);

int	is_number(const char *num)
{
	if (*num == '\0')
		return (0);
	while (*num != '\0')
	{
		if (*num < '0' || *num > '9')
			return (0);
		num++;
	}
	return (1);
}

int	dict_error(void)
{
	write(1, "Dict Error\n", 11);
	return (1);
}

int	convert_number(char *num, const char *path)
{
	char	*buffer;
	t_entry	*dict;
	size_t	count;
	int		ok;

	buffer = ft_read_file(path);
	if (buffer == NULL)
		return (dict_error());
	count = 0;
	dict = ft_parse_dict(buffer, &count);
	ok = 0;
	if (dict != NULL && count > 0)
		ok = numtoletter(num, dict, count);
	free(dict);
	free(buffer);
	if (ok == 0)
		return (dict_error());
	return (0);
}

int	main(int argc, char **argv)
{
	char	*path;

	if (argc < 2 || argc > 3 || !is_number(argv[argc - 1]))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	path = "numbers.dict";
	if (argc == 3)
		path = argv[1];
	return (convert_number(argv[argc - 1], path));
}
