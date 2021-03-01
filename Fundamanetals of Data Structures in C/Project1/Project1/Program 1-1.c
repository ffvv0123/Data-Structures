#include <stdio.h>

int main() {
	int i, * pi;
	double d, * pd;

	pi = (int*)malloc(sizeof(int));
	pd = (double*)malloc(sizeof(double));

	*pi = 1024;
	*pd = 3.14;

	printf("an integer = %d, a double = %f\n", *pi, *pd);

	free(pi);
	free(pd);

	return 0;
}