#include<stdio.h>
int function(int x);
int main()
{
	int b;
	int x;
	
	printf("Entre value of x : ");
	scanf("%d", &x);

	b = function(x);
	printf("La solution est %d \n ", b);
	
}
