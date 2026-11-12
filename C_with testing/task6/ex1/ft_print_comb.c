/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:23:04 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/24 14:37:46 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	digit_1;
	char	digit_2;
	char	digit_3;

	digit_1 = '0';
	while (digit_1 <= '7')
	{
		digit_2 = digit_1 +1;
		while (digit_2 <= '8')
		{
			digit_3 = digit_2 +1;
			while (digit_3 <= '9')
			{
				ft_putchar(digit_1);
				ft_putchar(digit_2);
				ft_putchar(digit_3);
				if (!(digit_1 == '7' && digit_2 == '8' && digit_3 == '9'))
					write(1, ", ", 2);
				digit_3++;
			}
			digit_2++;
		}
		digit_1++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
