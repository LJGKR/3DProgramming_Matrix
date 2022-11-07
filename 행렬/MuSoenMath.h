#pragma once
#include <iostream>
using namespace std;

class Vec3
{
private :
	

public :
	float v[1][3] =
	{
		{2,2,1}
	}; 
	float a[1][3];
	float b[1][3];
	float c[1][3];

};

class Mat3
{
	
public:
	float Translate[3][3] = {
		{1, 0, 0},
		{0, 1, 0},
		{3, 5, 1}
	};

	float Scale[3][3] = {
		{2, 0, 0},
		{0, 2, 0},
		{0, 0, 1} 
	};

	float Rotate[3][3] = {
		{0.15,-0.5, 0},
		{0.5,0.15, 0},
		{0, 0, 1}
	};
private:

};
Vec3 vec;
Mat3 mat;

void operate()
{
	for (int i = 0; i < 1; i++) {
			for (int k = 0; k < 3; k++) {
				for (int j = 0; j < 3; j++) {
					vec.a[i][k] += vec.v[i][j] * mat.Translate[j][k];
				}
			}
	}
	/*--------------------------------------------------------------*/
	for (int i = 0; i < 1; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				vec.b[i][k] += vec.a[i][j] * mat.Rotate[j][k];
			}
		}
	}
	//----------------------------------------------------------------
	for (int i = 0; i < 1; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				vec.c[i][k] += vec.b[i][j] * mat.Scale[j][k];
			}
		}
	}
	//----------------------------------------------------------------
	cout << "Vec3 pÀÇ ÁÂÇ¥ : \n";
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "{" << vec.c[i][j] << "}";
		}
		cout << "   ";
	}
}