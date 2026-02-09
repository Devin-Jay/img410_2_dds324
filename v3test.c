#include "v3math.h"


int main(int argc, char* argv[])
{
	float a[3] = {1, 2, 3};
	float b[3] = {4, 5, 6};
	float c[3];

	v3_subtract(c, a, b);
	printf("c: %f %f %f\n", c[0], c[1], c[2]);

	v3_cross_product(c, a, b);
	printf("c: %f %f %f\n", c[0], c[1], c[2]);

	return 0;
}