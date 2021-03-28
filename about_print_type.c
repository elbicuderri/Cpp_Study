#include <stdio.h>

int main() {
	int a = 3;
	float b = 3.3f;
	double c = 3.33;

	printf("%i, %f, %f\n", a, b, c);

	int d[3];
	d[0] = a;
	d[1] = (int)b;
	d[2] = (int)c;

	printf("%i, %i, %d\n", d[0], d[1], d[2]);

	float e[3];

	e[0] = (float)(*d);
	e[1] = (float)(*(d+1));
	e[2] = (float)(*(d+2));

	printf("%f, %f, %f\n", e[0], e[1], e[2]);
	return 0;
}
