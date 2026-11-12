#include <stdio.h>

int *ft_range(int min, int max);

int main(void){

	int min = 4;
	int max = 5;
	int *array = ft_range(min, max);
	for (int i =0; i < max - min; i++)
		printf("%d \n", array[i]);	
	free(array);
	return(0);
}

