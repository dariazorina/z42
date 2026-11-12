#include <stdio.h>

char *ft_strcapitalize(char *str);

int main(void){


	char str[] = "#qP?3W!W"; 
	printf("%s \n", ft_strcapitalize(str));	

	char str1[] = "hello, how are you doing? 42words forty-two; fifty+and+one";
	printf("%s \n", ft_strcapitalize(str1));	
	
	char str2[] = "1";
	printf("%s \n", ft_strcapitalize(str2));	
	
	char str3[] = "d";
	printf("%s \n", ft_strcapitalize(str3));	
	return(0);
}

