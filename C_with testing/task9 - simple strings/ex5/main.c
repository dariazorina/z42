#include <stdio.h>

char *ft_strupcase(char *str);

int main(void){


	char str[] = "dasha";
	printf("%s \n", ft_strupcase(str));	

	char str1[] = "q";
	printf("%s \n", ft_strupcase(str1));	
	
	char str2[] = "dDDDDasha";
	printf("%s \n", ft_strupcase(str2));	

	return(0);
}

