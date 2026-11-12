#include <stdlib.h>
#include <stdio.h>

char *ft_convert_base(char *nbr, char *base_from, char *base_to);

int main(void){

	char *res;
//	res = ft_convert_base("-01010101", "01", "0123456789");

//	res = ft_convert_base("-85", "0123456789", "01");
	res = ft_convert_base("-85", "0123456789", "poneyvif");

	printf(res);

	free(res);	
	return(0);
}

