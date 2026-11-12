#include <stdio.h>

void ft_swap(int *a, int *b);

int main(void)
{
	int first;
	int second;

	first = 30;
	second = 10;
	printf("Before: %d %d\n", first, second);
	ft_swap(&first, &second);
	printf("After: %d %d\n", first, second);
	return(0);
}
