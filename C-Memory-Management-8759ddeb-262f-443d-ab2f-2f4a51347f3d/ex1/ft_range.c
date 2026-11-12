/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/30 09:33:11 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 17:22:01 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int	*ft_range(int min, int max)
{
	int		*array;
	size_t	count;

	if (max <= min)
		return (NULL);
	count = (unsigned int)max - (unsigned int)min;
	if (count > SIZE_MAX / sizeof(*array))
		return (NULL);
	array = malloc(sizeof(int) * count);
	if (array == NULL)
		return (NULL);
	while (count > 0)
	{
		count--;
		max--;
		array[count] = max;
	}
	return (array);
}
