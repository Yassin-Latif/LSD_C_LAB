#include<stdio.h>

double f(double t)
{
	return t;
}

double Simpson(double a, double b, int n)
{
	int i;
	double h = (b - a) / n;
	double s = (f(a) + f(b)) / 6;
	for(i = 1; i < n; i++)
	{
		s+= f(a + i * h) / 3;
	}
	for(i = 0; i < n; i++)
	{
		s+= f(a + ((2 * i + 1) * h/2)) * 2/3;
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
	x = Simpson(a, b, n);
	printf("Result of Simpson is: %lf \n", x);
}



