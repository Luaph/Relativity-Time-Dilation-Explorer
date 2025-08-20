#include <raylib.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "DG.h"

// Placeholder mesh warping utilities (not yet used in main.c)

typedef struct WarpGrid {
	Mesh mesh;
	Vector3 *original;  // original positions
	int cols, rows;
	float spacing;
} WarpGrid;

WarpGrid *CreateWarpGrid(int cols, int rows, float spacing)
{
	if (cols < 2) cols = 2;
	if (rows < 2) rows = 2;
	WarpGrid *wg = (WarpGrid*)calloc(1, sizeof(WarpGrid));
	wg->cols = cols; wg->rows = rows; wg->spacing = spacing;
	int vx = cols * rows;
	Vector3 *positions = (Vector3*)MemAlloc(sizeof(Vector3) * vx);
	wg->original = (Vector3*)malloc(sizeof(Vector3) * vx);

	float width = (cols - 1) * spacing;
	float depth = (rows - 1) * spacing;
	float x0 = -width/2.0f;
	float z0 = -depth/2.0f;
	int k = 0;
	for (int j=0; j<rows; ++j) {
		for (int i=0; i<cols; ++i) {
			float x = x0 + i * spacing;
			float z = z0 + j * spacing;
			positions[k] = (Vector3){ x, 0.0f, z };
			wg->original[k] = positions[k];
			k++;
		}
	}

	int quads = (cols - 1) * (rows - 1);
	int indicesCount = quads * 6;
	unsigned short *indices = (unsigned short*)MemAlloc(sizeof(unsigned short) * indicesCount);
	int id = 0;
	for (int j=0; j<rows-1; ++j) {
		for (int i=0; i<cols-1; ++i) {
			int v0 = j*cols + i;
			int v1 = v0 + 1;
			int v2 = v0 + cols;
			int v3 = v2 + 1;
			indices[id++] = (unsigned short)v0;
			indices[id++] = (unsigned short)v2;
			indices[id++] = (unsigned short)v1;
			indices[id++] = (unsigned short)v1;
			indices[id++] = (unsigned short)v2;
			indices[id++] = (unsigned short)v3;
		}
	}

	Mesh mesh = {0};
	mesh.vertexCount = vx;
	mesh.triangleCount = quads * 2;
	mesh.vertices = (float*)MemAlloc(sizeof(float) * 3 * vx);
	for (int i=0; i<vx; ++i) {
		mesh.vertices[i*3+0] = positions[i].x;
		mesh.vertices[i*3+1] = positions[i].y;
		mesh.vertices[i*3+2] = positions[i].z;
	}
	mesh.indices = indices;
	UploadMesh(&mesh, true);

	MemFree(positions);
	wg->mesh = mesh;
	return wg;
}

void DestroyWarpGrid(WarpGrid *wg)
{
	if (!wg) return;
	UnloadMesh(wg->mesh);
	if (wg->original) free(wg->original);
	free(wg);
}

