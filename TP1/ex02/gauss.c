#include <stdio.h>
#include <stdlib.h>
#define N 10


float *remontee(float A[N][N], float B[N], int n)
{
  int i,j;
  float *x;
  float s;


  x = malloc(sizeof(float) * n);

  x[n - 1] = B[n - 1] / A[n -1][n - 1];
  
  for (i = n - 2; i >= 0; i--)
  {
     float s = 0;
     for (j = i + 1; j < n; j++)
     {
	     s += A[i][j] * x[j];
     }
     x[i] = (B[i] - s) / A[i][i];
  }

  return x;
}

float *gauss(float A[N][N] ,float B[N], int n)
{
  int i,j,k;
  float *x;

  x = malloc(sizeof(float) * n);

  
  for (k = 0; k < n - 1; k++)
  {
	 for (i = k + 1; i < n; i++)
	 {
		 float F = A[i][k] / A[k][k];
		 
		 for (j = k + 1; j < n; j++)
		 {
			 A[i][j] = A[i][j] - F * A[k][j];
		 }
		 B[i] = B[i] - F * B[k];
	 }
  } 
  x = remontee(A, B, n);
  return(x);
}

int main()
{
  float   A[N][N], B[N];
  float   *x;
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
  x = gauss(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

