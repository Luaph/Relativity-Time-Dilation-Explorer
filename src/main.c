#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <raylib.h>
#include "simulation.h"
#include "hud.h"

Camera camera = {
	.position = (Vector3){ 10.0f, 10.0f, 10.0f },
	.target = (Vector3){ 0.0f, 0.0f, 0.0f },
	.up = (Vector3){ 0.0f, 1.0f, 0.0f },
	.fovy = 45.0f,
	.projection = CAMERA_PERSPECTIVE,
};

int main(void)
{
	Simulation sim;
	SimInit(&sim, 5.9722e24);
	InitWindow(800, 800, "RG");
	SetTargetFPS(60);
	while (!WindowShouldClose()) {
		float dt = GetFrameTime();
		static int frame = 0; frame++;
		if ((frame & 30) == 0) {
			SetWindowTitle(TextFormat("RG (frame %d)", frame));
		}
		if (frame % 120 == 0) {
			printf("DEBUG frame=%d Rs=%e r=%e f=%f Tstep=%f\n", frame, sim.Rs, sim.r, sim.f, dt);
			fflush(stdout);
		}
		SimHandleInput(&sim, dt);
		SimUpdatePhysics(&sim, dt);
		BeginDrawing();
		ClearBackground(BLACK);
		BeginMode3D(camera);
		DrawGrid(10, 1);
		EndMode3D();
		DrawSimulationHUD(&sim, dt);
		DrawFPS(10, GetScreenHeight() - 30);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}
