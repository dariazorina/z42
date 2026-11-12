#include <stdlib.h>
#include <stdio.h>

char	*ft_strncpy(char *, char *, unsigned int);

int main(void){

	char *res;
	char dest[20] = "Hi ";
	char src[3] = "ab";
	res = ft_strncpy(dest, src, 1);

	printf(res);

	return(0);
}

