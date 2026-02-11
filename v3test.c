#include "v3math.h"

void newValues(float *a, float *b, float *newA, float *newB)
{
	a[0] = newA[0];
	a[1] = newA[1];
	a[2] = newA[2];

	b[0] = newB[0];
	b[1] = newB[1];
	b[2] = newB[2];
}

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
		printf("Test failed!//////////////////////////////////////////////////////\n\n");
	}
}

void printFloatResults(char *operation, float expected, float result, float *a, float *b, float tolerance)
{
	printf("%s:\n", operation);
	printf("Input:\n");
	printf("\ta: %f %f %f\n", a[0], a[1], a[2]);
	printf("\tb: %f %f %f\n", b[0], b[1], b[2]);
	printf("Output:\n");
	printf("\tresult: %f\n", result);
	printf("Expected:\n");
	printf("\tresult: %f\n", expected);

	if (fabs(result - expected) < tolerance) {
		printf("Test passed!\n\n");
	} else {
		printf("Test failed!//////////////////////////////////////////////////////\n\n");
	}
}

int main(int argc, char* argv[])
{
	float a[3] = {1.0f, 2.0f, 3.0f};
	float b[3] = {4.0f, 5.0f, 6.0f};
	float c[3], result;

	v3_subtract(c, a, b);
	printResults("v3_subtract", (float[]){-3.0f, -3.0f, -3.0f}, c, a, b, 0.001);

	newValues(a, b, (float[]){5.0f, -2.0f, 9.0f}, (float[]){5.0f, -2.0f, 9.0f});
	v3_subtract(c, a, b);
	printResults("v3_subtract", (float[]){0.0f, 0.0f, 0.0f}, c, a, b, 0.001);

	newValues(a, b, (float[]){-1.0f, 4.0f, -6.0f}, (float[]){2.0f, -2.0f, 3.0f});
	v3_subtract(c, a, b);
	printResults("v3_subtract", (float[]){-3.0f, 6.0f, -9.0f}, c, a, b, 0.001);

	newValues(a, b, (float[]){5.0f, -2.0f, 9.0f}, (float[]){5.0f, -2.0f, 9.0f});
	v3_from_points(c, a, b);
	printResults("v3_from_points", (float[]){0.0f, 0.0f, 0.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){-1.0f, 4.0f, -6.0f}, (float[]){2.0f, -2.0f, 3.0f});
	v3_from_points(c, a, b);
	printResults("v3_from_points", (float[]){3.0f, -6.0f, 9.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 1.0f, 1.0f}, (float[]){1.0f, 1.0f, 5.0f});
	v3_from_points(c, a, b);
	printResults("v3_from_points", (float[]){0.0f, 0.0f, 4.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	v3_cross_product(c, a, b);
	printResults("v3_cross_product", (float[]){0.0f, 0.0f, 1.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){0.0f, 1.0f, 0.0f}, (float[]){0.0f, 0.0f, 1.0f});
	v3_cross_product(c, a, b);
	printResults("v3_cross_product", (float[]){1.0f, 0.0f, 0.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 1.0f, 1.0f}, (float[]){2.0f, 2.0f, 2.0f});
	v3_cross_product(c, a, b);
	printResults("v3_cross_product", (float[]){0.0f, 0.0f, 0.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){2.0f, 0.0f, 0.0f});
	result = v3_angle(a, b);
	printFloatResults("v3_angle", 0.0f, result, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	result = v3_angle(a, b);
	printFloatResults("v3_angle", M_PI_2, result, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){-1.0f, 0.0f, 0.0f});
	result = v3_angle(a, b);
	printFloatResults("v3_angle", M_PI, result, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 2.0f, 3.0f}, (float[]){1.0f, 0.0f, 0.0f});
	v3_reflect(c, a, b);
	printResults("v3_reflect", (float[]){-1.0f, 2.0f, 3.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){-1.0f, 2.0f, 3.0f}, (float[]){0.0f, 1.0f, 0.0f});
	v3_reflect(c, a, b);
	printResults("v3_reflect", (float[]){-1.0f, -2.0f, 3.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, -1.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	v3_reflect(c, a, b);
	printResults("v3_reflect", (float[]){1.0f, 1.0f, 0.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){3.0f, 0.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	v3_normalize(c, a);
	printResults("v3_normalize", (float[]){1.0f, 0.0f, 0.0f}, c, a, a, 0.001f);

	newValues(a, b, (float[]){0.0f, 4.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	v3_normalize(c, a);
	printResults("v3_normalize", (float[]){0.0f, 1.0f, 0.0f}, c, a, a, 0.001f);

	newValues(a, b, (float[]){0.0f, 0.0f, 0.0f}, (float[]){1.0f, 1.0f, 1.0f});
	v3_normalize(c, a);
	printResults("v3_normalize", (float[]){0.0f, 0.0f, 0.0f}, c, a, a, 0.001f);

	//Jake Tests
	newValues(a, b, (float[]){1.0f, 2.0f, 3.0f}, (float[]){4.0f, 5.0f, 6.0f});
	v3_add(c, a, b);
	printResults("v3_add", (float[]){5.0f, 7.0f, 9.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){-1.0f, 4.0f, -6.0f}, (float[]){2.0f, -2.0f, 3.0f});
	v3_add(c, a, b);
	printResults("v3_add", (float[]){1.0f, 2.0f, -3.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){0.0f, 0.0f, 0.0f}, (float[]){7.0f, -8.0f, 9.0f});
	v3_add(c, a, b);
	printResults("v3_add", (float[]){7.0f, -8.0f, 9.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, 2.0f, 3.0f}, (float[]){4.0f, 5.0f, 6.0f});
	result = v3_dot_product(a, b);
	printFloatResults("v3_dot_product", 32.0f, result, a, b, 0.001f); 

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	result = v3_dot_product(a, b);
	printFloatResults("v3_dot_product", 0.0f, result, a, b, 0.001f);

	newValues(a, b, (float[]){-1.0f, 2.0f, -3.0f}, (float[]){4.0f, -5.0f, 6.0f});
	result = v3_dot_product(a, b);
	printFloatResults("v3_dot_product", -32.0f, result, a, b, 0.001f); 

	newValues(a, b, (float[]){1.0f, -2.0f, 3.0f}, (float[]){0.0f, 0.0f, 0.0f});
	c[0]=a[0]; c[1]=a[1]; c[2]=a[2]; //copy a into output (c)
	v3_scale(c, 2.0f);
	printResults("v3_scale", (float[]){2.0f, -4.0f, 6.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, -2.0f, 3.0f}, (float[]){0.0f, 0.0f, 0.0f});
	c[0]=a[0]; c[1]=a[1]; c[2]=a[2];
	v3_scale(c, 0.0f);
	printResults("v3_scale", (float[]){0.0f, 0.0f, 0.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){1.0f, -2.0f, 3.0f}, (float[]){0.0f, 0.0f, 0.0f});
	c[0]=a[0]; c[1]=a[1]; c[2]=a[2];
	v3_scale(c, -1.0f);
	printResults("v3_scale", (float[]){-1.0f, 2.0f, -3.0f}, c, a, b, 0.001f);

	newValues(a, b, (float[]){3.0f, 4.0f, 0.0f}, (float[]){0.0f, 0.0f, 0.0f});
	result = v3_length(a);
	printFloatResults("v3_length", 5.0f, result, a, a, 0.001f);

	newValues(a, b, (float[]){0.0f, 0.0f, 0.0f}, (float[]){0.0f, 0.0f, 0.0f});
	result = v3_length(a);
	printFloatResults("v3_length", 0.0f, result, a, a, 0.001f);

	newValues(a, b, (float[]){1.0f, 2.0f, 2.0f}, (float[]){0.0f, 0.0f, 0.0f});
	result = v3_length(a);
	printFloatResults("v3_length", 3.0f, result, a, a, 0.001f); 

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){2.0f, 0.0f, 0.0f});
	result = v3_angle_quick(a, b);
	printFloatResults("v3_angle_quick", 1.0f, result, a, b, 0.001f); //cos(0)=1

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){0.0f, 1.0f, 0.0f});
	result = v3_angle_quick(a, b);
	printFloatResults("v3_angle_quick", 0.0f, result, a, b, 0.001f); //cos(90)=0

	newValues(a, b, (float[]){1.0f, 0.0f, 0.0f}, (float[]){-1.0f, 0.0f, 0.0f});
	result = v3_angle_quick(a, b);
	printFloatResults("v3_angle_quick", -1.0f, result, a, b, 0.001f); //cos(180)=-1



	return 0;
}