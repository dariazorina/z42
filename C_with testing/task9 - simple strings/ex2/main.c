#include <stdio.h>

int ft_str_is_lowercase(char *str);

int main(void){

	printf("%d \n", ft_str_is_lowercase("Hello"));	
	printf("%d \n", ft_str_is_lowercase("123456a"));	
	printf("%d \n", ft_str_is_lowercase("1"));	
	printf("%d \n", ft_str_is_lowercase(""));	
	printf("%d \n", ft_str_is_lowercase("H"));	
	printf("%d \n", ft_str_is_lowercase("dfrtyggg"));	
	printf("%d \n", ft_str_is_lowercase("gbgbgbgY"));	
	printf("%d \n", ft_str_is_lowercase("a"));	
	
	return(0);
}

