#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define E 2.71828182845904523536

double f(double t)
{
	return t;
}

double rectangle_droite(double a, double b, int n)
{
	int i;
	double h = (b - a) / n;
	double s = 0;
	for (i = 0; i < n; i++)
	{
		s = s + f(a + i * h);
	}
	printf("Values of h is : %lf \n", h);
	printf("Values of s is : %lf \n", s);
	return h*s;
}

double rectangle_gauche(double a, double b, int n)
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


double Simpson(double(*f)(double),double a, double b, int n)
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

unsigned Nombre_Necessaire(double(*f)(double), double a, double b, double Err,double (*methode)(double(*)(double), double, double, int),double I)
{
	int n=1;
	while((methode(exp, a, b, n) - I) > Err || (methode(exp, a, b, n) < -Err))
	{
		n+=1;
	}
	return (n);
}

int main()
{
	double x, a ,b, Err;
	int n;
	printf("Values of a is : ");
	scanf("%lf", &a);
	printf("Values of b is : ");
	scanf("%lf", &b);
	printf("Values of n is : ");
	scanf("%d", &n);
	printf("Valus of Err is : ");
	scanf("%lf", &Err);
	x = Simpson(f, a, b, n);
	printf("Result of Methode is : %lf \n", x);
	printf("Number Necessery is : %u \n", Nombre_Necessaire(*f, a, b, Err, Simpson, E-1));
}

	
	
