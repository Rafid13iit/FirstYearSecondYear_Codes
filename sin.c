#include <stdio.h>
#include <math.h>
#define pi 22 / 7

float y (float x)
{
	return sin(x * pi / 180);
}

int main ()
{
	float x;
	for (x = -180; x <= 180; x++){
		printf("%f, %f\n", x, y(x));
	}

	return 0;
}
