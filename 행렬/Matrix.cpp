#include "MuSoenMath.h"
#include <math.h>
#include <iostream>

using namespace std;

void main() {
	Vec3 v;
	Mat3 Scale;

	v = Vec3(1, 1);
	Scale = Mat3(3,0,0,
		       0,5,0,
		       0,0,1);

	Vec3 k = v * Scale;

}