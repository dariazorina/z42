#include <stdio.h>

char *ft_strlowcase(char *str);

int main(void){


	char str[] = "DASHA";
	printf("%s \n", ft_strlowcase(str));	

	char str1[] = "q";
	printf("%s \n", ft_strlowcase(str1));	
	
	char str2[] = "";
	printf("%s \n", ft_strlowcase(str2));	
	
	char str3[] = "dD@DD--Dasha";
	printf("%s \n", ft_strlowcase(str3));	
	return(0);
}

