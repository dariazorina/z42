#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "dict.h"

char *ft_read_file(const char *) ;

int main(void){

	char *res;
	t_entry	*dict;
	size_t	count;

	res = ft_read_file("numbers.dict");
	printf("%s", res);

	dict = ft_parse_dict(res, &count);
	if (dict == NULL || count == 0)
	{
		free(dict);
		free(res);
		write(1, "Dict Error\n", 11);
		return (1);
	}

//dic must be ready

	free(dict);
	free(res);	
	return(0);
}

