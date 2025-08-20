// hud.c
// Implementation of HUD rendering.

#include <raylib.h>
#include <stdio.h>
#include "hud.h"

void DrawSimulationHUD(const Simulation *sim, float dt)
{
	if (!sim)
		return;
	int font, line, lines, pad, panelW, panelH, y, x;
	font = 18;
	line = font + 2;
	lines = 10;
	pad = 6;
	panelW = 420;
	panelH = pad*2 + lines * line + 4;
	DrawRectangle(6, 6, panelW, panelH, (Color){ 10, 10, 10, 180 });
	DrawRectangleLines(6, 6, panelW, panelH, (Color){120,120,120,255});
	y = 6 + pad;
	x = 14;
	DrawText(TextFormat("Rs: %.3e m", sim->Rs), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("r : %.3e m  (r/Rs=%.3f)", sim->r, sim->r / sim->Rs), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("f : %.3f c", sim->f), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("Tg: %.6f", sim->Tg), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("Tv: %.6f", sim->Tv), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("T : %.6f", sim->T), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("Coord t : %.3f s", sim->coord_time_global), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("Proper t: %.3f s", sim->proper_time_local), x, y, font, RAYWHITE); y += line;
	DrawText(TextFormat("dt: %.4f s", dt), x, y, font, RAYWHITE); y += line;
	DrawText("Keys W/S mass  Q/D radius  A/E vel  ESC quit", x, y, font-2, GRAY);
}
