#include <stdio.h>

char *ft_strdup(char *str);

int main(void){


	char str[] = "dasha";
	printf("%s \n", ft_strdup(str));	

	char str1[] = "";
	char str2[] = "1";
	char str3[] = "abcde FRTY";
	char str4[] = "@gh ^& 0-0-_fgfgasas ";
	
	printf("%s \n", ft_strdup(str1));	
	printf("%s \n", ft_strdup(str2));	
	printf("%s \n", ft_strdup(str3));	
	printf("%s \n", ft_strdup(str4));	
	
	return(0);
}

