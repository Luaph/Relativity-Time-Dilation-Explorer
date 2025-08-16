#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "DG.h"

const double c = 299792458.0;
const double G = 6.67430e-11;

double DG(double r, double M)
{
	// printf("%f, %f\n", r, M);
	double t = sqrt(1.0 - (2.0 * G * M) / (r * c * c));

	return (t);
}
