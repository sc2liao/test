#include <stdlib.h>
#include <stdio.h>

int* malloc_var(){
	int* tmpx = (int*)malloc(sizeof(int));
	return tmpx;
}
int main(){
	int* x = malloc_var();
	*x = 2;
	printf("the variable is%d",*x);
	//free(x);
	return 0;
}
