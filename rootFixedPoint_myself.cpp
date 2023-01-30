//root NR.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )
#define G(x)  ( sqrt((10 - (x)*(x)*(x)) / 4))
int main () {
  int i;
  double x0 = 1.5, x1 = 0, tol = 1e-5, fx1;
       // x0 =  1.5 initial guess
  
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
  printf("Itr       x0           x1           g(x0)           f(x1)\n");
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

  for (i=1; i< MAXN; i++) {

    x1 = G(x0);
    fx1 = F(x1);

    printf("%3d  %10lf  %10lf  %10lf  %10lf\n", i, x0, x1, x1, fx1);
   
    if (fabs(fx1) <= tol ) {
      printf("Root = %lf, Itr = %d\n", x1, i );
      return EXIT_SUCCESS;
    }

    x0 = x1;

  }
 
  printf("Itr Overflow ...\n");  
  return EXIT_FAILURE;
}
