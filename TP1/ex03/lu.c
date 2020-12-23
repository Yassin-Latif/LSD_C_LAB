#include <stdlib.h>
#include <stdio.h>
#define N 10

float *descente(float L[][N], float *B, int n)
{
 int i,j;
 float *y;
 float s;

 y = malloc(sizeof(float) * n);

 y[0] = B[0];
	for (i = 1; i < n; i++)
	{
		s=0;
		for (j = 0; j <= i-1; j++)
		{
			s += L[i][j] * y[j];
		}
		y[i] = B[i] - s;
	}
	return y;
}

float *remontee(float A[][N], float *y, int n)
{
 int i,j;
 float s;
 float *x;


 x = malloc(sizeof(float) * n);



 x[n - 1] = y[n - 1] / A[n -1][n -1];
	for (i = n - 2; i >= 0; i--)
	{
		s = 0;
		for (j = i+1; j <= n - 1; j++)
			s += A[i][j] * x[j];
		x[i] = (y[i] - s) / A[i][i];
	}
	return x;
}

 float *lu(float A[][N], float *B, int n)
{
  int k,i,j;
  float L[N][N];
  float *x;
  float *y;


  for (k = 0; k < n - 1; k++)
	{
		for (i = k + 1; i < n; i++)
		{
			L[i][k] = A[i][k] / A[k][k];
			for (j = k + 1; j < n; j++)
			{
				A[i][j] = A[i][j] - L[i][k] * A[k][j];
			}
		}
	}
        /* Calcul The Matrix Y (Methode descente) */
        
        y = descente(L, B, n);

	/* Calcul the Matrix X (Methode remontee) */

	x = remontee(A, y, n);

	return (x);
}

int main()
{
  float   A[N][N], B[N];
  float   *x;
  float   *y;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

