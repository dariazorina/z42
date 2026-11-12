#include <stdlib.h>
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int main(void){


	int *range;

	int min = 3;
	int max = 5;

	ft_ultimate_range(&range, min, max);

	for (int i=0; i<max -min; i++)
		printf("value=%d index=%d ", range[i], i);

	free(range);	
	return(0);
}

