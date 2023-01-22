#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 10
#define PI   3.14159

int main (void) {

double f[11]={1,1.04,1.16,1.36,1.64,2,2.44,2.96,3.56,4.24,5};
double x[11]={0,.2,.4,.5,.8,1,1.2,1.4,1.6,1.8,2};
double df[11];
for(int i=0;i<11;i++)
{
if(i==0)
{
df[i]=((f[i+1]-f[i])/(x[i+1]-x[i]));
}
else if(i==10)
{
df[i]=((f[i]-f[i-1])/(x[i]-x[i-1]));
}
else
{
df[i]=((f[i+1]-f[i-1])/(x[i+1]-x[i-1]));
}
}
printf("n\txi\t  fxi\t  dfxi\n----------------------------------------------\n");
for(int j=0;j<11;j++)
{

printf("%3d     %lf     %lf     %lf\n",j,x[j],f[j],df[j]);
}

 /* int i,
  double a=0, b=2, h;
  double x[MAXN + 1], f[MAXN + 1],df[max+1];
 
 
  h = (b - a)/MAXN;
  x[0] = a;
  for (i=1; i< MAXN; i++)
    x[i] = x[i-1] + h;
  x[i] = b;

  for (i=0; i<= MAXN; i++)
    sinx[i] = sin(x[i]);

  printf("\"x\",\"sin(x)\"\n");
  for (i=0; i<= MAXN; i++)
    printf("%lf,%lf\n", x[i],sinx[i] );

*/
  return EXIT_SUCCESS;
}