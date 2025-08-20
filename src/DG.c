#include <math.h>
#include "DG.h"

double DG(double r, double M)
{
	return sqrt(1.0 - (2.0 * G * M) / (r * c * c));
}
