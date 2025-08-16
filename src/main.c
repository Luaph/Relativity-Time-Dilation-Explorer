#include "DG.h"
#include "DC.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	char *end;
	double r, M, v;

	if (argc == 3)
	{
		end = 0;
		r = strtod(argv[1], &end);
		if (*end != '\0')
			printf("%s", "First argument is not valid");
		M = strtod(argv[2], &end);
		if (*end != '\0')
			printf("%s", "Second argument is not valid");
		printf("%.20f\n", DG(r, M));
	}
	else if (argc == 4)
	{
		end = 0;
		r = strtod(argv[1], &end);
		if (*end != '\0')
			printf("%s", "First argument is not valid");
		M = strtod(argv[2], &end);
		if (*end != '\0')
			printf("%s", "Second argument is not valid");
		v = strtod(argv[3], &end);
		if (*end != '\0')
			printf("%s", "Third argument is not valid");
		printf("%.20f\n", DC(r, M, v));
	}
	else
		printf("Please read the github README to understand how to use this program\n");
	return (0);
}
