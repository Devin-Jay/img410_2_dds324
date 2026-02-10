#include "v3math.h"

void printResults(char *operation, float *expected, float *c, float *a, float *b, float tolerance)
{
	printf("%s:\n", operation);
	printf("Input:\n");
	printf("\ta: %f %f %f\n", a[0], a[1], a[2]);
	printf("\tb: %f %f %f\n", b[0], b[1], b[2]);
	printf("Output:\n");
	printf("\tc: %f %f %f\n", c[0], c[1], c[2]);
	printf("Expected:\n");
	printf("\tc: %f %f %f\n", expected[0], expected[1], expected[2]);

	if (fabs(c[0] - expected[0]) < tolerance &&
		fabs(c[1] - expected[1]) < tolerance &&
		fabs(c[2] - expected[2]) < tolerance) {
		printf("Test passed!\n\n");
	} else {
		printf("Test failed!\n\n");
	}
}

int main(int argc, char* argv[])
{
	float a[3] = {1, 2, 3};
	float b[3] = {4, 5, 6};
	float c[3];

	v3_subtract(c, a, b);
	printResults("v3_subtract", (float[]){-3, -3, -3}, c, a, b, 0.001);

	v3_cross_product(c, a, b);
	printResults("v3_cross_product", (float[]){-3, 6, -3}, c, a, b, 0.001);

	return 0;
}