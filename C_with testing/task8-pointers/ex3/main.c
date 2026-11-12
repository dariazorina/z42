#include <stdio.h>

void ft_div_mod(int a, int b, int *div, int *mod);

void main(void){

	int div_res;
	int mod_res;

	ft_div_mod(17, 5, &div_res, &mod_res);
	printf("Division %d \n", div_res);
	printf("Remainder %d \n", mod_res);
	
}

