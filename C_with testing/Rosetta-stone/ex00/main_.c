/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeli-wi <rgeli-wi@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 12:48:13 by rgeli-wi          #+#    #+#             */
/*   Updated: 2026/11/08 14:29:10 by rnorouzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "dict.h"
#include <stdlib.h>
#include <unistd.h>

char	*ft_read_file(const char *path);
t_entry	*ft_parse_dict(char *buffer, size_t *count);
int numtoletter(char *num, t_entry *dict, int count);

int	main(int argc, char **argv)
{
	char	*path;
	char	*res;
	t_entry	*dict;
	size_t	count;
	int	i;

	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = 0;
       	while (argv[1][i] != '\0')
       	{
	       	if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            write(1, "Error\n", 6);
            return (1);
        }
        i++;
       	}	
	if (argc == 2)
		path = "numbers.dict";
	else if (argc == 3)
		path = argv[2];
	res = ft_read_file(path);
	dict = ft_parse_dict(res, &count);
	if (dict == NULL || count == 0)
	{
		free(dict);
		free(res);
		write(1, "Dict Error\n", 11);
		return (1);
	}
       	if (numtoletter(argv[1], dict, count) == 0)
	{
	       	write(1, "Dict Error\n", 11);
		return (1);
	}
	free(dict);
        free(res);
	return (0);

}
