#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

int main(void){

	int tab[5];
	int i;

	tab[0] = 77;
	tab[1] = 66;
	tab[2] = 55;
	tab[3] = 44;
	tab[4] = 33;
	ft_rev_int_tab(tab, 5);
	i = 0;
	while(i<5){
		printf("%d ", tab[i]);
		i++;
	}
	return(0);
}
