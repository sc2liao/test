#include<stdio.h>
#include<stdlib.h>

int main(){
	//char x = 'c';
	char *x = NULL;
	char *x_ = x;
	printf("xptr is %p\n",x);
	printf("x_ ptr is %p\n",x_);
	x_ = (char*)malloc(sizeof(char));
	printf("xptr is %p\n",x);
	printf("x_ ptr is %p\n",x_);
	*x = 'c';
	return 0;

}