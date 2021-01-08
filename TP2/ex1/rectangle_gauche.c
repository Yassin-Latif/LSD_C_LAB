#include <stdio.h>

double f(double t)
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
		s+= f(a + (i+1) * h);
	}
	printf("Values of h is : %lf \n", h);
	printf("Values of s is : %lf \n", s);
	return h*s;
}

int main()
{
	double a, b;
	int n;
	double x;
	printf("La valeur de a est : ");
	scanf("%lf", &a);
	printf("La valeur de b est : ");
	scanf("%lf", &b);	
	printf("La valeur de n est : ");
	scanf("%d", &n);
	x = rectangle_gauche(a,b, n);
	printf("Result of Rectangle Gauche is : %lf", x);
}
