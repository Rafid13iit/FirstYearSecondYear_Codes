#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define F(x)  ( 3*(x) - cos(x) - 1 )

int main () {
  int i;
  double a=0, b=1, tol = 1.0e-5, c;
  double fa,fb,fc;

  /*  "tol" is a variable that stands for tolerance, 
  which is a small positive value used to determine the accuracy of the approximation of the root. 
  It is used to check if the current approximation of the root
  is sufficiently close to the actual root within a certain degree of accuracy. */
 
  fa = F(a);   fb = F(b);

  if (fa*fb >= 0 ) {
    printf("No Root ...\n");
    return EXIT_FAILURE;
  }

  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("Itr       a           b           c           f(a)        f(b)        f(c)\n");
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");

  for (i=1; i< MAXN; i++) {
    c = (a * fb - b * fa) / (fb - fa);
    fc = F(c);

    printf("%3d  %10lf  %10lf  %10lf  %10lf  %10lf  %10lf\n", i, a, b, c, fa, fb, fc);
   
    if (fabs(fc) <= tol ) { //checks if the absolute value of "fc" is less than or equal to the tolerance "tol"
      printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
      printf("Approximate Root = %lf, Itr = %d\n", c, i);
      return EXIT_SUCCESS;
    }
   
    if (fa*fc <= 0 ) {
      b = c;
      fb = fc;
    } else {
      a = c;
      fa = fc;
    }
  }
 
  printf("Itr Overflow ...\n");  
  return EXIT_FAILURE;
}