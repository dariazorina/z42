#include <stdlib.h>
#include <stdio.h>

char	*ft_strcat(char *, char *);

int main(void){

	char *res;
	char dest[20] = "Hi ";
	char src[3] = "ab";
	res = ft_strcat(dest, src);

	printf(res);

	return(0);
}

