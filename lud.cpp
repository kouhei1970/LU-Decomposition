#include <stdio.h>


short matPrint(double* mat, short M, short N);

int main(){

  double A[25]={
    1.0, 2.0, 3.0,
    4.0, 5.0, 6.0,
    6.0, 8.0, 9.0,
  };
  double B[25]={0.0};

  double sum;
  short i,j,k;
  short m=5;
  short n=5;

  for (i=0; i<m; i++)
  {
    for (j=0; j<n; j++)
    {
      sum=0.0;
      for (k=0; k<i; k++)
      {
        sum=sum+B[i*m+k]*B[k*m+j];
      }

      if(i<=j)
      {
        B[i*m+j]=A[i*m+j]-sum;
      }
      else
      {
        B[i*m+j]=(A[i*m+j]-sum)/B[j*m+j];
      }
    }
  }

  matPrint(A, m, n);
  matPrint(B, m, n);

}

short matPrint(double* mat, short M, short N){
  short i,j;
  for (i=0;i<M;i++){
    for (j=0;j<N;j++){
      printf("%8.5f " ,mat[i*N+j]);
    }
    printf("\n");
  }
  printf("\n");
}

