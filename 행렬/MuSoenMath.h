#pragma once
#include <iostream>
using namespace std;

struct Vec3
{
private:

public:

	int k = 3;
	float vec3[3][1];
	float vec[3][1];

	Vec3() {
		vec3[0][0] = 0, vec3[1][0] = 0, vec[2][0] = 0;
	}

	Vec3(float v1, float v2, int i = 1) {
		vec3[0][0] = v1, vec3[1][0] = v2, vec3[2][0] = i;
	}

	Vec3& operator*(const Mat3& ref) {                     //���Ϳ� ����� ����

		if (k == 3) {
			this->vec[0][0] = vec3[0][0] * ref.mat3[0][0] + vec3[1][0] * ref.mat3[1][0] + vec3[2][0] * ref.mat3[2][0];
			this->vec[1][0] = vec3[0][0] * ref.mat3[0][1] + vec3[1][0] * ref.mat3[1][1] + vec3[2][0] * ref.mat3[2][1];
			this->vec[2][0] = vec3[0][0] * ref.mat3[0][2] + vec3[1][0] * ref.mat3[1][2] + vec3[2][0] * ref.mat3[2][2];

			this->vec3[0][0] = vec[0][0], this->vec3[1][0] = vec[1][0], this->vec3[2][0] = vec[2][0];

			return *this;
		}
		if (k == 1) {

		}
	}
};



struct Mat3
{
private:

public:
	float mat3[3][3];


	Mat3() {                     //�� ���� ���� ������ �⺻������ ��Ŀ� ���� ��
		mat3[0][0] = 0, mat3[0][1] = 0, mat3[0][2] = 0,
		mat3[1][0] = 0, mat3[1][1] = 0, mat3[1][2] = 0,
		mat3[2][0] = 0, mat3[2][1] = 0, mat3[2][2] = 0;
	};

	Mat3(float m1, float m2, float m3,float m4, float m5, float m6,
		float m7, float m8, float m9) {
		mat3[0][0] = m1, mat3[0][1] = m2, mat3[0][2] = m3,
		mat3[1][0] = m4, mat3[1][1] = m5, mat3[1][2] = m6,
		mat3[2][0] = m7, mat3[2][1] = m8, mat3[2][2] = m9;
	};

	void Reset() {                //��İ��� 0���� �ʱ�ȭ ��Ű�� �Լ�
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				mat3[i][k] = 0;
			}
		}
	}

	void Identity() {             //������� �ʱ�ȭ �Լ�
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				mat3[i][k] = 0;
			}
		}
		mat3[0][0] = 1, mat3[1][1] = 1, mat3[2][2] = 1;
	}
};