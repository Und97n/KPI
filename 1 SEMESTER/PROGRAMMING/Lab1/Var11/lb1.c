#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double e = 2.71828182846;

double _pow(double a, double p) {
	return exp(log(a) * p);
}

int main(int argc, char** argv) {
	if(argc < 4) {
		printf("Not enough arguments");

		return 1;
	}

	double x, y, z;

	sscanf(argv[1], "%lf", &x);
	sscanf(argv[2], "%lf", &y);
	sscanf(argv[3], "%lf", &z);

	double tmp = exp(x - y) - 1;

	if(x < y) {
		printf("Incorrect input: sqrt(m<0)\n");

		return 1;
	}

	double tmp1 = sqrt(tmp);

	double tmp2 = tmp1 + _pow(x, abs(y)) + z;

	if(tmp2 <= 0) {
		printf("Incorrect input: log(m<=0)");

		return 1;
	}

	const double a = log(tmp2);

	double tmp3 = x * x * x;

	if((y == 0) || (z == 0)) {
		printf("Incorrect input: m/0");

		return 1;
	}

	const double b = x - tmp3 / y + (tmp3 * x * x) / z;

	printf("a = %lf\n", a);
	printf("b = %lf\n", b);
}
