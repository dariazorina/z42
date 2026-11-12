#include <stdio.h>

void  ft_putstr_non_printable(char *str);

int main(void){

	ft_putstr_non_printable("\xff");	
	printf("\n");
	ft_putstr_non_printable("Hello	How are you ?");	
	printf("\n");
	ft_putstr_non_printable("Hello\tHow are you ?");	
	printf("\n");
	printf("\n");
	ft_putstr_non_printable("Hello\rHow are you ?");	

	printf("\n");
	ft_putstr_non_printable("Hello\x15How are you ?");	
	printf("\n");
	ft_putstr_non_printable("Hello\x22How are you ?");	
	printf("\n");
	ft_putstr_non_printable("Hello\x11How are you ?");	
	printf("\n");
	ft_putstr_non_printable("Hello\xbdHow are you ?");	
	printf("\n");
	ft_putstr_non_printable("Hello\xa3How are you ?");	
	printf("\n");
	ft_putstr_non_printable("Hello\x65How are you ?");
	printf("\n");
	ft_putstr_non_printable("");
	printf("\n");
	ft_putstr_non_printable("\x1f");
	printf("\n");
	ft_putstr_non_printable("\x7f");
	return(0);
}

