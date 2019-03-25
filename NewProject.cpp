#include <CoalaMOD.h>
#include <stdio.h>
#pragma comment(lib, "CoalaMOD.lib")
#include <math.h>


int main() {

	double pi = 3.14159265358979323846;

	BlockID sand = createBlock(BLOCK_RED_SAND);

	int px, py, pz;
	int a, b, c;

	getPlayerLocation(&px, &py, &pz);

	double dir = getPlayerDirection();

	double radian = dir * pi / 180.;

	int dx = -100 * sin(radian);

	int dz = 100 * cos(radian);

	px += dx;

	pz += dz;

	printf("%d %d %d", px, py, pz);

	for (a = 0; a < 50; a++) {
		for (b = a - 50; b < 51 - a; b++) {
			for (c = a - 50; c < 51 - a; c++) {
				locateBlock(sand, px + c, py + a, pz + b);
			}
		}
	}

}