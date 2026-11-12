#include <stdio.h>

int ft_str_is_printable(char *str);

int main(void){

	printf("%d \n", ft_str_is_printable("H W"));	
	printf("%d \n", ft_str_is_printable("1WSa"));	
	printf("%d \n", ft_str_is_printable(""));	
	printf("%d \n", ft_str_is_printable("\t"));	
	printf("%d \n", ft_str_is_printable("\n"));	
	printf("%d \n", ft_str_is_printable("d"));	
	printf("%d \n", ft_str_is_printable("\x01 g"));	
	printf("%d \n", ft_str_is_printable("HGKUYOPUGVBVCVZXCBV"));	
	
	return(0);
}

