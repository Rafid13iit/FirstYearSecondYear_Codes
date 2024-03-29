//root NR.c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )

int main (void) {
  int i;
  double x0=1.5, x1=2, x2, tol = 10.0e-6;
  double fx0,fx1,fx2;
 
  fx0 = F(x0);   fx1 = F(x1);

  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("Itr       x0          x1          x2         f(x0)       f(x1)       f(x2)\n");
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

  for (i=1; i< MAXN; i++) {
    x2 = x1 - fx1*(x1 - x0)/(fx1 - fx0);
    fx2 = F(x2);

    printf("%3d  %10lf  %10lf  %10lf  %10lf  %10lf  %10lf\n", i, x0, x1, x2, fx0, fx1, fx2);
   
    if (fabs(fx2) <= tol ) {
      printf("Root = %lf, Itr = %d\n", x2,i );
      return EXIT_SUCCESS;
    }

    x0 = x1;
    x1 = x2;
    fx0 = fx1;
    fx1 = fx2;
  }
 
  printf("Itr Overflow ...\n");  
  return EXIT_FAILURE;
}
