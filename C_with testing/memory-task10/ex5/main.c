#include <stdlib.h>
#include <stdio.h>


#include <stdio.h>

char **ft_split(char *str, char *charset);

int main(void){

	char **res;

	res = ft_split("+wild*#+++forest+", "*#+");
//	int     i;
 //       i = 0;
//      while (res[0][i] != '\0') 
//

	if (res != NULL)
	{

		printf(res[0]);
		printf("\n");
		printf(res[1]);
//i++;
		printf("\n");
		printf(res[2]);
//

	free(res);	
	} 
	else 
		printf("NULL");

	return(0);
}

