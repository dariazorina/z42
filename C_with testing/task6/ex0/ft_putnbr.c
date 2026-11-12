/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 13:14:42 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/24 14:19:26 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_digits(long n)
{
	char	digits[10];	
	int		index;

	index = 0;
	while (n > 0)
	{
		digits[index] = (n % 10) + '0';
		n = n / 10;
		index++;
	}
	while (index > 0)
	{
		index--;
		write(1, &digits[index], 1);
	}
}

void	ft_putnbr(int nb)
{
	long	n;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_print_digits(n);
}

int	main(void)
{
	ft_putnbr(-52);
	write(1, "\n", 1);
}
