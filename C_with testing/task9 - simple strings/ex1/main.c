#include <stdio.h>

int ft_str_is_numeric(char *str);

int main(void){

	printf("%d \n", ft_str_is_numeric("Hello"));	
	printf("%d \n", ft_str_is_numeric("123456P"));	
	printf("%d \n", ft_str_is_numeric("1"));	
	printf("%d \n", ft_str_is_numeric(""));	
	printf("%d \n", ft_str_is_numeric("H"));	
	printf("%d \n", ft_str_is_numeric("-12"));	
	printf("%d \n", ft_str_is_numeric("23424323423423423423423423423423"));	
	printf("%d \n", ft_str_is_numeric("0"));	
	
	return(0);
}

