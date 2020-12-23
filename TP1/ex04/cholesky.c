#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

float *descente(float C[N][N], float *B, int n)
{
 int i,j;
 float *y;
 float s1;

 y = malloc(sizeof(float) * n);

 y[0] = B[0] / C[0][0];

 for (i = 1; i < n; i++)
 {
	 s1 = 0;
	 for (j = 0; j < i; j++)
	 {
		 s1 += C[i][j] * y[j];
	 }
	 y[i] = (B[i] - s1) / C[i][i];
 }


 
 
 return (y);
}

float *remontee(float C[N][N], float *y, int n)
{
 float *x;
 int i,j;
 float s2;

 x = malloc(sizeof(float) * n);

 x[n - 1] = y[n - 1] / C[n - 1][n - 1];

 for (i = n -2; i >= 0; i--)
 {
	 s2 = 0;
	 for (j = i + 1; j < n; j++)
	 {
		 s2 += C[j][i] * x[j];
	 }
	 x[i] = (y[i] - s2) / C[i][i];

 }
 return (x);

}

float cholesky(float C[N][N], float A[N][N],int n)
{
	//cholesky algorithm		
	for(int j = 0; j < n; j++){
		for(int i = j; i < n; i++){
			if(i == j)
      {
				float sum1 = 0;
				for(int k = 0; k < j; k++){
					sum1 += C[i][k]*C[i][k];
			  }
				C[i][j] = sqrt(A[i][j]-sum1);
			}
			else
      {
				float sum2 = 0;
				for(int k=0; k < j; k++){
					sum2 += C[i][k]*C[j][k];
				}
				C[i][j]=(A[i][j]-sum2)/C[j][j];
			}
		}
	}
	return C[N][N];
}

int main()
{
  int n;
        /* The matrix dimension */
	float A[N][N], B[N], *y, *x, C[N][N];
	printf("Enter the dimension of the matrix :");
	scanf("%d", &n);
        /* Filling the matrix A */
	printf("Filling the matrix A\n");
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n ; j++){
			printf("A[%d][%d]= ", i, j);
			scanf("%f", &A[i][j]);
			}
        /* Filling the matrix B */
	printf("Filling the matrix B\n");
	for(int i=0; i < n; i++){
		printf("B[%d]=", i);
		scanf("%f", &B[i]);
		}


	//implementation of the C matrix 
	for(int i = 0; i < n; i++)
  {
		for(int j = 0; j < n; j++){
			C[i][j]=0;
		}
	}
	
	
	
	//find the resulting cholesky matrix
	C[N][N]=cholesky(C, A, n);
  
	//printing  C
	printf("Here is the C matrix \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
    {
		printf("C[%d][%d] = %f\t",i, j, C[i][j]);
		}
		printf("\n");
	}
	
	//Printing C(T) 
	printf("Here is the C(T) matrix \n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
    {
		printf("C[%d][%d] = %f\t",i, j, C[j][i]);
		}
		printf("\n");
	}
	
	/* Calcul the matrix y */
	y = descente(C, B, n);
	//printing Y
	printf("The Matrix Y is :\n");
	for(int i = 0; i < n ; i++)
  {
		printf("y[%d]=%f\t",i, y[i]);
	}
	
	/* Calcul the matrix x */
	x = remontee(C, y, n);

	//printing X
	printf("\n the final solution is :\n");
	for(int i=0; i < n; i++)
		printf("x[%d]=%f\t",i, x[i]);
  return (0);
} 
