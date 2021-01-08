#include<stdio.h>

double f(double t)
{
	return t;
}

double Trapeze(double a, double b, int n)
{
	int i;
	double h = (b - a) / n;
	double s = (f(a) + f(b)) / 2;
	for(i = 1; i < n; i++)
	{
		s+= f(a + i * h);
	}
	return h * s;
}

int main()
{
	double a, b, x;
	int n;
	printf("Values of a is : ");
	scanf("%lf", &a);
	printf("Values of b is : ");
	scanf("%lf", &b);
	printf("Values of n is : ");
	scanf("%d", &n);
	x = Trapeze(a, b, n);
	printf("Result of Trapeze is : %lf \n", x);
}
		
