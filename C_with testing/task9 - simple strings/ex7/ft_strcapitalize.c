/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 12:11:07 by dzorina           #+#    #+#             */
/*   Updated: 2026/10/28 19:22:46 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alphanumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_lowcar(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	is_upcar(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	if (is_alphanumeric(str[index])
		&& !(is_numeric(str[index])) && (is_lowcar(str[index])))
		str[index] = str[index] - 32;
	if (is_alphanumeric(str[index]))
		index++;
	while (str[index] != '\0')
	{
		if (is_alphanumeric(str[index]) && is_upcar(str[index]))
			str[index] = str[index] + 32;
		if (!is_alphanumeric(str[index])
			&& str[index +1] != '\0' && is_alphanumeric(str[index +1]))
		{
			index++;
			if (!is_numeric(str[index]) && is_lowcar(str[index]))
				str[index] = str[index] - 32;
		}
		index++;
	}
	return (str);
}
