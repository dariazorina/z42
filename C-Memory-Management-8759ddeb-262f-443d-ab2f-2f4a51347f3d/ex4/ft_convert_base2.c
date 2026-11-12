/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 14:15:06 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 17:56:03 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_base_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
	{
		return (1);
	}
	else
	{
		while (base[i] != '\0')
		{
			if (ft_is_space(base[i]) || base[i] == '+' || base[i] == '-')
				return (1);
			j = i + 1;
			while (base[j])
			{
				if (base[i] == base[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int	ft_base_digit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
