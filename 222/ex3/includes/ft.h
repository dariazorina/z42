/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkutlu <hkutlu@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 10:21:36 by hkutlu            #+#    #+#             */
/*   Updated: 2026/11/11 12:34:30 by hkutlu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

typedef struct s_file
{
	char	*name;
	char	*content;
	int		size;
}	t_file;

t_file	ft_add_file(char *filename);
void	ft_putnstr(char *str, int n);
void	ft_putstr(char *str, int out);
int		ft_display_hex(char *line, int rc);
void	ft_display_str(char *line, int rc);
int		ft_read(int *size, char *line, int file, int need);
int		ft_display_error(char *filename);
void	ft_display_size(int nbr);
int		ft_display_line(char *line, int size, int rc);

#endif
