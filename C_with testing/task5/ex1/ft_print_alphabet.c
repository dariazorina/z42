/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:35:27 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/21 19:25:28 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	symbol;

	symbol = 'a';
	while (symbol <= 'z')
	{
		write(1, &symbol, 1);
		symbol++;
	}
}
