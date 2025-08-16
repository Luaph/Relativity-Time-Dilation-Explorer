#include <math.h>
#include <stdio.h>
#include <stdlib.h>
const double c = 299792458.0;
const double G = 6.67430e-11;

double DG(double r, double M)
{
	printf("%f, %f\n", r, M);
	double t = sqrt(1.0 - (2.0 * G * M) / (r * c * c));

	return (t);
}

int main(int argc, char **argv)
{
	(void)argc;
	char *end;
	double r, M;

	end = 0;
	r = strtod(argv[1], &end);
	if (*end != '\0')
	{
		printf("%s", "First argument is not valid");
		return 1;
	}
	M = strtod(argv[2], &end);
	if (*end != '\0')
	{
		printf("%s", "Second argument is not valid");
		return 1;
	}
	printf("%.20f\n", DG(r, M));
}
