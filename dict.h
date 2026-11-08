#ifndef DICT_H
# define DICT_H

#include <stddef.h>

typedef struct s_entry
{
	char	*key;
	char	*value;
}	t_entry;

t_entry	*ft_parse_dict(char *buffer, size_t *count);

#endif