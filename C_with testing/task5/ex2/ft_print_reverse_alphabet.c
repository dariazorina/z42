/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 19:29:23 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/21 19:41:43 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	symbol;

	symbol = 'z';
	while (symbol >= 'a')
	{
		write(1, &symbol, 1);
		symbol--;
	}
}
