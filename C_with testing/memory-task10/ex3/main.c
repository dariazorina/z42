#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(int size, char **strs, char *sep);

int main(void){


	char *strs[] = {"", "Test2", "Test3"};
	char sep[] = " - ";
	char *res;
	

	res = ft_strjoin(3, strs, sep);

	printf(res);

	free(res);	
	return(0);
}

