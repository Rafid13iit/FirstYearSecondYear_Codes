#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( (x)*(x)*(x) + 4*(x)*(x) - 10 )
#define DF(x)  ( 3*(x)*(x) + 8*(x) )

int main () {
  int i;
  double x0 = 1.5, x1, tol = 1e-5;
  double fx1, fx2, dfx1;
 
  fx1 = F(x0);   dfx1 = DF(x0);

  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("Itr       x0          x1         f(x0)      f'(x0)      f(x1)\n");
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");

  for (i=1; i< MAXN; i++) {
    x1 = x0 - fx1/dfx1;
    fx2 = F(x1);

    printf("%3d  %10lf  %10lf  %10lf  %10lf  %10lf\n", i, x0, x1, fx1, dfx1, fx2);
   
    if (fabs(fx2) <= tol ) {
      printf("\nRoot = %lf, Itr = %d\n", x1, i );
      return EXIT_SUCCESS;
    }

    x0 = x1;
    fx1 = fx2;
    dfx1 = DF(x1);
  }
 
  printf("Itr Overflow ...\n");  
  return EXIT_FAILURE;
}