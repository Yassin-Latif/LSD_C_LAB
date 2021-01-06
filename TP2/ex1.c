#include <stdio.h>

double f(int t)
{
	return t;
}

double rectangle_gauche( double a, double b, int n)
{
	int i;
	double h = (b - a) / n;
	float s = 0;
	for (i = 0; i < n; i++)
	{
		s+= f(a + i * h);
	}
	return h*s;
}

int main()
{
	double a, b;
	int n;
	printf("La valeur de a est : ");
	scanf("%lf", &a);
	printf("La valeur de b est : ");
	scanf("%lf", &b);	
	printf("La valeur de n est : ");
	scanf("%d", &n);
	double x;
	x = rectangle_gauche(a,b, n);
	printf("Result is : %lf", x);
}
