/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:41:37 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/24 14:55:03 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_two_digits(int number)
{
	ft_putchar((number / 10) + '0');
	ft_putchar((number % 10) + '0');
}

void	ft_print_pair(int first, int second)
{
	ft_put_two_digits(first);
	ft_putchar(' ');
	ft_put_two_digits(second);
	if (!(first == 98 && second == 99))
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;

	first = 0;
	while (first <= 98)
	{
		second = first + 1;
		while (second <= 99)
		{
			ft_print_pair(first, second);
			second++;
		}
		first++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
