#include <stdio.h>

double f(int t)
{
	return t;
}

double rectangle_droite( double a, double b, int n)
{
	int i;
	double h = (b - a) / n;
	float s = 0;
	for (i = 1; i <= n; i++)
	{
		s+= f(a + (i+1) * h);
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
	x = rectangle_droite(a,b, n);
	printf("Result is : %lf", x);
}
