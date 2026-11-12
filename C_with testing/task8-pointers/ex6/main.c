#include <stdio.h>

void ft_sort_int_tab(int *tab, int size);

int main(void){

	int tab[6];
	int i;

	tab[0] = 77;
	tab[1] = -16;
	tab[2] = 5;
	tab[3] = 44;
	tab[4] = 3;
	tab[5] = -2;

	ft_sort_int_tab(tab, 6);
	i = 0;
	while(i<6){
		printf("%d \n", tab[i]);
		i++;
	}
	return(0);
}
