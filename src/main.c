#include "DG.h"
#include "DC.h"
#include <stdlib.h>
#include <stdio.h>
#include <raylib.h>

Camera camera = {
	.position = (Vector3){ 10.0f, 10.0f, 10.0f },
	.target = (Vector3){ 0.0f, 0.0f, 0.0f },
	.up = (Vector3){ 0.0f, 1.0f, 0.0f },
	.fovy = 45.0f,
	.projection = CAMERA_PERSPECTIVE,
};

int main(int argc, char **argv)
{
	char *end;
	double r, M, v;

	InitWindow(800, 800, "RG");
	SetTargetFPS(144);

	while (WindowShouldClose() == false)
	{
		BeginDrawing();
		BeginMode3D(camera);
		ClearBackground(BLACK);
		DrawGrid(10, 1);

		EndMode3D();
		EndDrawing();
	}

	CloseWindow();
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
