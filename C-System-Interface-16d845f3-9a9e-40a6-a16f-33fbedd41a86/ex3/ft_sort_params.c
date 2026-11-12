/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 17:22:37 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/09 18:18:15 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_print(int argc, char **argv)
{
	int	i;
	int	j;

	j = 1;
	while (j < argc)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write(1, &argv[j][i], 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*r;

	j = 0;
	if (argc > 0)
	{
		while (argc - 1 - j > 1)
		{
			i = 1;
			while (i < argc - j - 1)
			{
				if (ft_strcmp(argv[i], argv[i + 1]) > 0)
				{
					r = argv[i];
					argv[i] = argv[i + 1];
					argv[i + 1] = r;
				}
				i++;
			}
			j++;
		}
		ft_print(argc, argv);
	}
	return (0);
}
