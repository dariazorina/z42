/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:28:10 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/09 14:08:03 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	found_index;

	i = 0;
	found_index = 0;
	if (*to_find == '\0')
		return (str);
	while (str[i] != '\0')
	{
		found_index = 0;
		while (str[i + found_index] == to_find[found_index]
			&& to_find[found_index] != '\0')
		{
			found_index++;
			if (to_find[found_index] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}
