#include <stdio.h>

int ft_str_is_uppercase(char *str);

int main(void){

	printf("%d \n", ft_str_is_uppercase("HSW"));	
	printf("%d \n", ft_str_is_uppercase("1WSa"));	
	printf("%d \n", ft_str_is_uppercase("1"));	
	printf("%d \n", ft_str_is_uppercase(""));	
	printf("%d \n", ft_str_is_uppercase("H"));	
	printf("%d \n", ft_str_is_uppercase("d"));	
	printf("%d \n", ft_str_is_uppercase("SSSSSSg"));	
	printf("%d \n", ft_str_is_uppercase("HGKJHKJHLKHLKHLKJHLKHLKHLKHKPOUYOPUGVBVCVZXCBV"));	
	
	return(0);
}

