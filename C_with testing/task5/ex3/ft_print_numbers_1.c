/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:43:19 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/21 20:16:13 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char digit;

	digit = '1';
	while (digit <= '9')
	{
		write(1, &digit, 1);
		digit++;
	}
}

void	main(void)
{
	ft_print_numbers();
}
