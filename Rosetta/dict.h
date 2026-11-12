/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzorina <dzorina@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 11:27:24 by dzorina           #+#    #+#             */
/*   Updated: 2026/11/08 11:28:37 by dzorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H

# include <stddef.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}			t_entry;

t_entry		*ft_parse_dict(char *buffer, size_t *count);

#endif
