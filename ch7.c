#include <stdio.h>
#include <stdlib.h>

int* add(int* a, int* b, int L)
{
	int* c = (int*)malloc(L * sizeof(int));

	for (int i = 0; i < L; i++) {
		c[i] = a[i] + b[i];
	}

	//free(c); ??

	return c;
}


int main()
{
	int* x = (int*)malloc(3 * sizeof(int));
	int* y = (int*)malloc(3 * sizeof(int));

	for (int i = 0; i < 3; i++) {
		x[i] = 2 * i;
	}

	for (int i = 0; i < 3; i++) {
		y[i] = 3 * i - 2;
	}

	int* z = (int*)malloc(3 * sizeof(int));

	z = add(x, y, 3);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", z[i]);
	}

	free(x);
	free(y);
	free(z);
	//free(c); ??

	return 0;
}