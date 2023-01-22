#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXN 200
#define PI 3.14159
int main ()
{
	int n = MAXN;
	double x[MAXN + 1], sinx[MAXN + 1], cosx[MAXN + 1];
	double a = 0, b = 2 * PI;

	double delx = (b - a) / 200;

	x[0] = a;

	for (int i = 1; i < n; i++){
		a += delx;
		x[i] = a;
	}

	x[n] = b;

	for (int i = 0; i <= n; i++){
		sinx[i] = sin(x[i]);
	}

	for (int i = 0; i <= n; i++){
		cosx[i] = cos(x[i]);
	}

	printf("\"x\",\"sin(x)\",\"cos(x)\"\n");

	for (int i = 0; i <= n; i++){
		printf("%lf,%lf,%lf\n", x[i], sinx[i], cosx[i]);
	}

	
	return 0;
}
