#ifndef SIMULATION_H
#define SIMULATION_H

#include <raylib.h>

typedef struct Simulation
{
	double M, Rs, r, f, epsilon, f_max, proper_time_local, coord_time_global, Tg, Tv, T, rMin;
} Simulation;

void SimInit(Simulation *sim, double initialMass);
void SimHandleInput(Simulation *sim, float dt);
void SimUpdatePhysics(Simulation *sim, float dt);

#endif // SIMULATION_H
