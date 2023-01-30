#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x)   ( (x)*(x) + 1 )
#define MAXN 10

int main (void) {
  int i;
  double a = 0, b = 2, n = 10, h, x[MAXN + 1], y[MAXN + 1], df[MAXN + 1];

  h = (b - a)/ n;
  
  x[0] = a; 
  for (i=1; i<n; i++) x[i] = x[i-1] + h;
  x[i] = b; 

  for (i=0; i<=n; i++) y[i] = f(x[i]);

  for (i=0; i<=n; i++) df[i] = ( y[i+1] - y[i-1] )/( x[i+1] - x[i-1] );   

  printf("- - - - - - - - - - - - - - - - - - - -\n");
  printf("  i    x[i]       y[i]       df[i]\n");
  printf("- - - - - - - - - - - - - - - - - - - -\n");

  for (i=0; i<= n; i++)
    printf("%3d %10lf %10lf %10lf\n",i,x[i],y[i],df[i] );
    
  printf("- - - - - - - - - - - - - - - - - - - -\n");

   return EXIT_SUCCESS;
}