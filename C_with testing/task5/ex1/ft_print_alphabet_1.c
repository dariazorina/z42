/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:35:27 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/21 19:16:56 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void) 
{	
	char symbol = 'a';

	while (symbol <= 'z')
	{
		write(1, &symbol, 1);
		symbol++;
	}
}

void	main(void) {
	ft_print_alphabet();
}

