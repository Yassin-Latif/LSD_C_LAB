#include <stdio.h>
#include <stdlib.h>
#define N 10

float *remontee(float A[N][N], float B[N], int n)
{
  float     *x;
  float      s;
  int        i,j;

  /* A hint: you cant return an array which is allocated in the stack memory */
  x = malloc(sizeof(float) * n);

  
  x[n - 1] = B[n - 1] / A[n -1][n-1];

  for (i = n-2 ; i >= 0; i--)
  {
	  s = 0;
	  for (j = i + 1; j < n; j++)
	  {
		 s += A[i][j] * x[j];
	  }
	  x[i] = (B[i] - s) / A[i][i];
  } 
  
  return x;
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
  printf("Filling the vector B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = remontee(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

