#include <stdlib.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int main(void){

	char *res;
	res = ft_strstr("abc", "");

	printf(res);

	return(0);
}

