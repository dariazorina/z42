/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 10:06:02 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 17:20:43 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	size_t	count;
	size_t	i;

	if (range == NULL)
		return (-1);
	*range = NULL;
	if (max <= min)
		return (0);
	count = (unsigned int)max - (unsigned int)min;
	if (count > INT_MAX || count > SIZE_MAX / sizeof(**range))
		return (-1);
	*range = malloc(sizeof(**range) * count);
	if (*range == NULL)
		return (-1);
	i = count;
	while (i > 0)
	{
		i--;
		max--;
		(*range)[i] = max;
	}
	return ((int)count);
}
