#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

void main(void){

	int a;
	int b;

	a = 24;
	b = 5;

	ft_ultimate_div_mod(&a, &b);
	printf("div %d\n", a);	
	printf("rem %d\n", b);
}
