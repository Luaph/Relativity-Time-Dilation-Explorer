#include <math.h>
#include "simulation.h"
#include "DG.h"
#include "constants.h"

static const double massChangeRate = 0.05;
static const double radialChangeRate = 0.5;
static const double fChangeRate = 0.25;

void SimInit(Simulation *sim, double initialMass)
{
	if (!sim)
		return;
	sim->M = initialMass;
	sim->epsilon = 1e-4;
	sim->f_max = 0.99;
	sim->f = 0.0;
	sim->Rs = 2.0 * G * sim->M / (c * c);
	sim->r = 10.0 * sim->Rs;
	sim->proper_time_local = 0.0;
	sim->coord_time_global = 0.0;
	sim->Tg = 1.0;
	sim->Tv = 1.0;
	sim->T  = 1.0;
	sim->rMin = (1.0 + sim->epsilon) * sim->Rs;
}

void SimHandleInput(Simulation *sim, float dt)
{
	if (!sim) return;
	if (IsKeyDown(KEY_W))
	{
		sim->M *= (1.0 - massChangeRate * dt);
		if (sim->M < 1.0) sim->M = 1.0;
	}
	if (IsKeyDown(KEY_S))
	{
		sim->M *= (1.0 + massChangeRate * dt);
	}
	if (IsKeyDown(KEY_Q))
	{
		sim->r -= sim->r * radialChangeRate * dt;
	}
	if (IsKeyDown(KEY_E))
	{
		sim->r += sim->r * radialChangeRate * dt;
	}
	if (IsKeyDown(KEY_A))
	{
		sim->f -= fChangeRate * dt;
	}
	if (IsKeyDown(KEY_D))
	{
		sim->f += fChangeRate * dt;
	}
	if (sim->f < 0.0)
		sim->f = 0.0;
	if (sim->f > sim->f_max)
		sim->f = sim->f_max;
}

void SimUpdatePhysics(Simulation *sim, float dt)
{
	if (!sim)
		return;
	sim->Rs = 2.0 * G * sim->M / (c * c);
	sim->rMin = (1.0 + sim->epsilon) * sim->Rs;
	if (sim->r < sim->rMin)
		sim->r = sim->rMin;
	sim->Tg = DG(sim->r, sim->M);
	sim->Tv = sqrt(1.0 - sim->f * sim->f);
	if (sim->Tv < 0.0)
		sim->Tv = 0.0;
	sim->T = sim->Tg * sim->Tv;
	sim->coord_time_global += dt;
	sim->proper_time_local += sim->T * dt;
}
