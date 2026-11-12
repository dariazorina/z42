#include <stdlib.h>
#include <stdio.h>

char	*ft_strncat(char *, char *, unsigned int);

int main(void){

	char *res;
	char dest[20] = "Hi ";
	char src[2] = {'a', 'b'};
	res = ft_strncat(dest, src, 2);

	printf(res);

	return(0);
}

