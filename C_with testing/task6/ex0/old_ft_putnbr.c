/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 10:18:01 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/23 11:52:37 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putnbr(int nb)
{
	long	number;
	char	digits[10];
	int	i;	

	number = nb;
	i = 0;
	if (number == 0)
	{
		write(1, "0", 1);
	}
	if (number < 0)
	{
		write(1, "-", 1);
		number = -number;
	}

	while (number > 0)
	{
		digits[i] = (number % 10) + '0';
		printf("-- %i  %i \n", digits[i], i);
		i++;
		number = number / 10;
	}
	while (i > 0)
	{
		printf("%i \n", i);
		i--;
		write(1, &digits[i], 1);
	}
}


int main(void){
	ft_putnbr(345);
	return(0);
}

