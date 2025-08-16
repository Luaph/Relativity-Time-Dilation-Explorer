#include <math.h>
#include "DC.h"
#include "DG.h"

double DC(double r, double M, double v)
{
	return (DG(r, M) * sqrt(1.0 - (v * v) / (c * c)));
}
