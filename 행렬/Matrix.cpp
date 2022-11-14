#include "MuSoenMath.h"
#include <math.h>
#include <iostream>

using namespace std;

void main() {
	
	Mat3 m;
	Mat3 r;
	Mat3 k;

	m = Mat3(6, 5, 4,
		4, 4, 4,
		4, 4, 4);

	r = Mat3(2, 2, 2,
		2, 2, 2,
		2, 2, 2);

	m.print();
	
	k = m - r;

	k.print();

}