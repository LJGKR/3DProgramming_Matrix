#pragma once
#include <iostream>
using namespace std;

struct Mat3
{
private:

public:
	float mat3[3][3];
	float transmat[3][3];
	float multmat[3][3];


	Mat3() {                     //값 없이 선언만 했을때 기본적으로 행렬에 들어가는 값
		this->mat3[0][0] = 0, this->mat3[0][1] = 0, this->mat3[0][2] = 0,
			this->mat3[1][0] = 0, this->mat3[1][1] = 0, this->mat3[1][2] = 0,
			this->mat3[2][0] = 0, this->mat3[2][1] = 0, this->mat3[2][2] = 0;
	};

	Mat3(float m1, float m2, float m3, float m4, float m5, float m6,
		float m7, float m8, float m9) {
		this->mat3[0][0] = m1, this->mat3[0][1] = m2, this->mat3[0][2] = m3,
			this->mat3[1][0] = m4, this->mat3[1][1] = m5, this->mat3[1][2] = m6,
			this->mat3[2][0] = m7, this->mat3[2][1] = m8, this->mat3[2][2] = m9;
	};

	void Reset() {                //행렬값을 0으로 초기화 시키는 함수
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				mat3[i][k] = 0;
			}
		}
	}

	void Identity() {             //단위행렬 초기화 함수
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				mat3[i][k] = 0;
			}
		}
		mat3[0][0] = 1, mat3[1][1] = 1, mat3[2][2] = 1;
	}

	void Transpose() {
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				transmat[i][k] = mat3[i][k];
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				mat3[i][k] = transmat[k][i];
			}
		}
	}

	void print() {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << " " << "{" << mat3[i][j] << "]";
			}
			cout << endl;
		}
		cout << endl;

	}

	Mat3 operator*(Mat3& ref) {


		this->multmat[0][0] = mat3[0][0] * ref.mat3[0][0] + mat3[0][1] * ref.mat3[1][0] + mat3[0][2] * ref.mat3[2][0];
		this->multmat[0][1] = mat3[0][0] * ref.mat3[0][1] + mat3[0][1] * ref.mat3[1][1] + mat3[0][2] * ref.mat3[2][1];
		this->multmat[0][2] = mat3[0][0] * ref.mat3[0][2] + mat3[0][1] * ref.mat3[1][2] + mat3[0][2] * ref.mat3[2][2];
		this->multmat[1][0] = mat3[1][0] * ref.mat3[0][0] + mat3[1][1] * ref.mat3[1][0] + mat3[1][2] * ref.mat3[2][0];
		this->multmat[1][1] = mat3[1][0] * ref.mat3[0][1] + mat3[1][1] * ref.mat3[1][1] + mat3[1][2] * ref.mat3[2][1];
		this->multmat[1][2] = mat3[1][0] * ref.mat3[0][2] + mat3[1][1] * ref.mat3[1][2] + mat3[1][2] * ref.mat3[2][2];
		this->multmat[2][0] = mat3[2][0] * ref.mat3[0][0] + mat3[2][1] * ref.mat3[1][0] + mat3[2][2] * ref.mat3[2][0];
		this->multmat[2][1] = mat3[2][0] * ref.mat3[0][1] + mat3[2][1] * ref.mat3[1][1] + mat3[2][2] * ref.mat3[2][1];
		this->multmat[2][2] = mat3[2][0] * ref.mat3[0][2] + mat3[2][1] * ref.mat3[1][2] + mat3[2][2] * ref.mat3[2][2];

		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				mat3[i][k] = multmat[i][k];
			}
		}
		return *this;
	}

	Mat3 operator+(Mat3& ref) {

		Mat3 m;
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				m.mat3[i][k] = mat3[i][k] + ref.mat3[i][k];
			}
		}
		return m;
	}

	Mat3 operator-(Mat3& ref) {
		Mat3 m;
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < 3; k++) {
				m.mat3[i][k] = mat3[i][k] - ref.mat3[i][k];
			}
		}
		return m;
	}
};

struct Mat4
{
private:

public:
	float mat4[4][4];
	float transmat[4][4];
	float multmat[4][4];
	float plusmat[4][4];
	float minmat[4][4];


	Mat4() {                     //값 없이 선언만 했을때 기본적으로 행렬에 들어가는 값
		mat4[0][0] = 0, mat4[0][1] = 0, mat4[0][2] = 0,
			mat4[1][0] = 0, mat4[1][1] = 0, mat4[1][2] = 0,
			mat4[2][0] = 0, mat4[2][1] = 0, mat4[2][2] = 0,
			mat4[3][0] = 0, mat4[3][1] = 0, mat4[3][2] = 0;

	};

	Mat4(float m1, float m2, float m3, float m4, float m5, float m6,
		float m7, float m8, float m9, float m10, float m11, float m12) {
		mat4[0][0] = m1, mat4[0][1] = m2, mat4[0][2] = m3,
			mat4[1][0] = m4, mat4[1][1] = m5, mat4[1][2] = m6,
			mat4[2][0] = m7, mat4[2][1] = m8, mat4[2][2] = m9,
			mat4[3][0] = m10, mat4[3][1] = m11, mat4[3][2] = m12;
	};

	void Reset() {                //행렬값을 0으로 초기화 시키는 함수
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				mat4[i][k] = 0;
			}
		}
	}

	void Identity() {             //단위행렬 초기화 함수
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				mat4[i][k] = 0;
			}
		}
		mat4[0][0] = 1, mat4[1][1] = 1, mat4[2][2] = 1, mat4[3][3] = 1;
	}

	void Transpose() {
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				transmat[i][k] = mat4[i][k];
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				mat4[i][k] = transmat[k][i];
			}
		}
	}

	void print() {

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << " " << mat4[i][j];
			}
			cout << endl;
		}
		cout << endl;

	}

	Mat4 operator*(Mat4& ref) {
		this->multmat[0][0] = mat4[0][0] * ref.mat4[0][0] + mat4[0][1] * ref.mat4[1][0] + mat4[0][2] * ref.mat4[2][0];
		this->multmat[0][1] = mat4[0][0] * ref.mat4[0][1] + mat4[0][1] * ref.mat4[1][1] + mat4[0][2] * ref.mat4[2][1];
		this->multmat[0][2] = mat4[0][0] * ref.mat4[0][2] + mat4[0][1] * ref.mat4[1][2] + mat4[0][2] * ref.mat4[2][2];
		this->multmat[0][3] = mat4[0][0] * ref.mat4[0][3] + mat4[0][1] * ref.mat4[1][3] + mat4[0][2] * ref.mat4[2][3];

		this->multmat[1][0] = mat4[1][0] * ref.mat4[0][0] + mat4[1][1] * ref.mat4[1][0] + mat4[1][2] * ref.mat4[2][0];
		this->multmat[1][1] = mat4[1][0] * ref.mat4[0][1] + mat4[1][1] * ref.mat4[1][1] + mat4[1][2] * ref.mat4[2][1];
		this->multmat[1][2] = mat4[1][0] * ref.mat4[0][2] + mat4[1][1] * ref.mat4[1][2] + mat4[1][2] * ref.mat4[2][2];
		this->multmat[1][3] = mat4[1][0] * ref.mat4[0][3] + mat4[1][1] * ref.mat4[1][3] + mat4[1][2] * ref.mat4[2][3];

		this->multmat[2][0] = mat4[2][0] * ref.mat4[0][0] + mat4[2][1] * ref.mat4[1][0] + mat4[2][2] * ref.mat4[2][0];
		this->multmat[2][1] = mat4[2][0] * ref.mat4[0][1] + mat4[2][1] * ref.mat4[1][1] + mat4[2][2] * ref.mat4[2][1];
		this->multmat[2][2] = mat4[2][0] * ref.mat4[0][2] + mat4[2][1] * ref.mat4[1][2] + mat4[2][2] * ref.mat4[2][2];
		this->multmat[2][3] = mat4[2][0] * ref.mat4[0][3] + mat4[2][1] * ref.mat4[1][3] + mat4[2][2] * ref.mat4[2][3];

		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				mat4[i][k] = multmat[i][k];
			}
		}
		return *this;
	}

	Mat4 operator+(Mat4& ref) {
		Mat4 m;
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				m.mat4[i][k] = mat4[i][k] + ref.mat4[i][k];
			}
		}
		return m;
	}

	Mat4 operator-(Mat4& ref) {
		Mat4 m;
		for (int i = 0; i < 4; i++) {
			for (int k = 0; k < 4; k++) {
				m.mat4[i][k] = mat4[i][k] - ref.mat4[i][k];
			}
		}
		return m;
	}
};

struct Vec3
{
private:

public:

	bool t = true;
	float vec3[3][3];
	float vec[3][3];

	Vec3() {
		this->vec3[0][0] = 0, this->vec3[1][0] = 0, this->vec3[2][0] = 0;
	}

	Vec3(float v1, float v2, float v3) {
		this->vec3[0][0] = v1, this->vec3[1][0] = v2, this->vec3[2][0] = v3;
	}

	Vec3 operator*( Mat3& ref) {                     //백터와 행렬의 연산

		if (t) {
			this->vec[0][0] = vec3[0][0] * ref.mat3[0][0] + vec3[1][0] * ref.mat3[1][0] + vec3[2][0] * ref.mat3[2][0];
			this->vec[1][0] = vec3[0][0] * ref.mat3[0][1] + vec3[1][0] * ref.mat3[1][1] + vec3[2][0] * ref.mat3[2][1];
			this->vec[2][0] = vec3[0][0] * ref.mat3[0][2] + vec3[1][0] * ref.mat3[1][2] + vec3[2][0] * ref.mat3[2][2];

			this->vec3[0][0] = vec[0][0], this->vec3[1][0] = vec[1][0], this->vec3[2][0] = vec[2][0];

			return *this;
		}
		if (t == false) {
			this->vec[0][0] = vec3[0][0] * ref.mat3[0][0] + vec3[0][1] * ref.mat3[1][0] + vec3[0][2] * ref.mat3[2][0];
			this->vec[0][1] = vec3[0][0] * ref.mat3[0][1] + vec3[0][1] * ref.mat3[1][1] + vec3[0][2] * ref.mat3[2][1];
			this->vec[0][2] = vec3[0][0] * ref.mat3[0][2] + vec3[0][1] * ref.mat3[1][2] + vec3[0][2] * ref.mat3[2][2];

			this->vec3[0][0] = vec[0][0], this->vec3[0][1] = vec[0][1], this->vec3[0][2] = vec[0][2];
			
			return *this;
		}
	}

	Vec3 operator*( Vec3& rv) {
		if (t == true) {
			this->vec[0][0] = vec3[0][0] * rv.vec3[0][0];
			this->vec[1][0] = vec3[1][0] * rv.vec3[1][0];
			this->vec[2][0] = vec3[2][0] * rv.vec3[2][0];

			this->vec3[0][0] = vec[0][0];
			this->vec3[1][0] = vec[1][0];
			this->vec3[2][0] = vec[2][0];
		}
		else if (t == false) {
			this->vec[0][0] = vec3[0][0] * rv.vec3[0][0];
			this->vec[0][1] = vec3[0][1] * rv.vec3[0][1];
			this->vec[0][2] = vec3[0][2] * rv.vec3[0][2];

			this->vec3[0][0] = vec[0][0];
			this->vec3[0][1] = vec[0][1];
			this->vec3[0][2] = vec[0][2];
		}
		return *this;
	}

	Vec3 operator+( Vec3& ref) {
		if (t == true) {
			this->vec[0][0] = vec3[0][0] + ref.vec3[0][0];
			this->vec[1][0] = vec3[1][0] + ref.vec3[1][0];
			this->vec[2][0] = vec3[2][0] + ref.vec3[2][0];

			this->vec3[0][0] = vec[0][0];
			this->vec3[1][0] = vec[1][0];
			this->vec3[2][0] = vec[2][0];
		}
		else if (t == false) {
			this->vec[0][0] = vec3[0][0] + ref.vec3[0][0];
			this->vec[0][1] = vec3[0][1] + ref.vec3[0][1];
			this->vec[0][2] = vec3[0][2] + ref.vec3[0][2];

			this->vec3[0][0] = vec[0][0];
			this->vec3[0][1] = vec[0][1];
			this->vec3[0][2] = vec[0][2];
		}
		return *this;
	}

	Vec3 operator-( Vec3& ref) {
		if (t == true) {
			this->vec[0][0] = vec3[0][0] - ref.vec3[0][0];
			this->vec[1][0] = vec3[1][0] - ref.vec3[1][0];
			this->vec[2][0] = vec3[2][0] - ref.vec3[2][0];

			this->vec3[0][0] = vec[0][0];
			this->vec3[1][0] = vec[1][0];
			this->vec3[2][0] = vec[2][0];
		}
		else if (t == false) {
			this->vec[0][0] = vec3[0][0] - ref.vec3[0][0];
			this->vec[0][1] = vec3[0][1] - ref.vec3[0][1];
			this->vec[0][2] = vec3[0][2] - ref.vec3[0][2];

			this->vec3[0][0] = vec[0][0];
			this->vec3[0][1] = vec[0][1];
			this->vec3[0][2] = vec[0][2];
		}
		return *this;
	}

	void Transpose() {
		if (t == true)
		{
			vec3[0][1] = vec3[1][0];
			vec3[0][2] = vec3[2][0];
			t = false;
		}
		else if (t == false)
		{
			vec3[1][0] = vec3[0][1];
			vec3[2][0] = vec3[0][2];
			t = true;
		}
	}

	void print() {

		cout << "위치 값: " << endl;
		if (t == true)
		{
			for (int i = 0; i < 3; i++) {
				cout << " " <<"{" << vec3[i][0] << "}";
				cout << endl;
			}
		}
		else if (t == false)
		{
			for (int i = 0; i < 3; i++) {
				cout << " " <<"{"<< vec3[0][i]<<"}";
				cout << endl;
			}
		}

	}
};

struct Vec4 {
public:
	bool t = true;
	float vec4[4][4];
	float vec[4][4];

	Vec4() {
		this->vec4[0][0] = 0; this->vec4[1][0] = 0; this->vec4[2][0] = 0; this->vec4[3][0] = 0;
	}
	Vec4(float a, float b, float c, float d) {
		this->vec4[0][0] = a; this->vec4[1][0] = b; this->vec4[2][0] = c; this->vec4[3][0] = d;
	}
	void Transpose() {
		if (t == true)
		{
			for (int i = 1; i < 4; i++) {
				vec4[0][i] = vec4[i][0];
			}
			t = false;
		}
		else if (t == false)
		{
			for (int i = 1; i < 4; i++) {
				vec4[i][0] = vec4[0][i];
			}
			t = true;
		}
	}

	void print() {
		if (t == true)
		{
			for (int i = 0; i < 4; i++) {
				cout << " " << vec4[i][0];
				cout << endl;
			}
		}
		else if (t == false)
		{
			for (int i = 0; i < 4; i++) {
				cout << " " << vec4[0][i];
				cout << endl;
			}
		}

	}

	Vec4 operator*(Mat4& ref) {                     //백터와 행렬의 연산

		if (t) {
			this->vec[0][0] = vec4[0][0] * ref.mat4[0][0] + vec4[1][0] * ref.mat4[1][0] + vec4[2][0] * ref.mat4[2][0] + vec4[3][0] * ref.mat4[3][0];
			this->vec[1][0] = vec4[0][0] * ref.mat4[0][1] + vec4[1][0] * ref.mat4[1][1] + vec4[2][0] * ref.mat4[2][1] + vec4[3][0] * ref.mat4[3][1];
			this->vec[2][0] = vec4[0][0] * ref.mat4[0][2] + vec4[1][0] * ref.mat4[1][2] + vec4[2][0] * ref.mat4[2][2] + vec4[3][0] * ref.mat4[3][2];
			this->vec[3][0] = vec4[0][0] * ref.mat4[0][3] + vec4[1][0] * ref.mat4[1][3] + vec4[2][0] * ref.mat4[2][3] + vec4[3][0] * ref.mat4[3][3];
			

			this->vec4[0][0] = vec[0][0], this->vec4[1][0] = vec[1][0], this->vec4[2][0] = vec[2][0], this->vec4[3][0] = vec[3][0];

			return *this;
		}
		if (t == false) {
			this->vec[0][0] = vec4[0][0] * ref.mat4[0][0] + vec4[0][1] * ref.mat4[1][0] + vec4[0][2] * ref.mat4[2][0] + vec4[0][3] * ref.mat4[3][0];
			this->vec[0][1] = vec4[0][0] * ref.mat4[0][1] + vec4[0][1] * ref.mat4[1][1] + vec4[0][2] * ref.mat4[2][1] + vec4[0][3] * ref.mat4[3][1];
			this->vec[0][2] = vec4[0][0] * ref.mat4[0][2] + vec4[0][1] * ref.mat4[1][2] + vec4[0][2] * ref.mat4[2][2] + vec4[0][3] * ref.mat4[3][2];
			this->vec[0][3] = vec4[0][0] * ref.mat4[0][3] + vec4[0][1] * ref.mat4[1][3] + vec4[0][2] * ref.mat4[2][3] + vec4[0][3] * ref.mat4[3][3];
			

			this->vec4[0][0] = vec[0][0], this->vec4[0][1] = vec[0][1], this->vec4[0][2] = vec[0][2], this->vec4[3][0] = vec[3][0];

			return *this;
		}
	}

	Vec4 operator*(Vec4& rv) {
		if (t == true) {
			this->vec[0][0] = vec4[0][0] * rv.vec4[0][0];
			this->vec[1][0] = vec4[1][0] * rv.vec4[1][0];
			this->vec[2][0] = vec4[2][0] * rv.vec4[2][0];
			this->vec[3][0] = vec4[3][0] * rv.vec4[3][0];

			this->vec4[0][0] = vec[0][0];
			this->vec4[1][0] = vec[1][0];
			this->vec4[2][0] = vec[2][0];
			this->vec4[3][0] = vec[3][0];
		}
		else if (t == false) {
			this->vec[0][0] = vec4[0][0] * rv.vec4[0][0];
			this->vec[0][1] = vec4[0][1] * rv.vec4[0][1];
			this->vec[0][2] = vec4[0][2] * rv.vec4[0][2];
			this->vec[0][3] = vec4[0][3] * rv.vec4[0][3];

			this->vec4[0][0] = vec[0][0];
			this->vec4[0][1] = vec[0][1];
			this->vec4[0][2] = vec[0][2];
			this->vec4[0][3] = vec[0][3];
		}
		return *this;
	}

	Vec4 operator+(Vec4& ref) {
		if (t == true) {
			this->vec[0][0] = vec4[0][0] + ref.vec4[0][0];
			this->vec[1][0] = vec4[1][0] + ref.vec4[1][0];
			this->vec[2][0] = vec4[2][0] + ref.vec4[2][0];
			this->vec[3][0] = vec4[3][0] + ref.vec4[3][0];

			this->vec4[0][0] = vec[0][0];
			this->vec4[1][0] = vec[1][0];
			this->vec4[2][0] = vec[2][0];
			this->vec4[3][0] = vec[3][0];
		}
		else if (t == false) {
			this->vec[0][0] = vec4[0][0] + ref.vec4[0][0];
			this->vec[0][1] = vec4[0][1] + ref.vec4[0][1];
			this->vec[0][2] = vec4[0][2] + ref.vec4[0][2];
			this->vec[0][3] = vec4[0][3] + ref.vec4[0][3];

			this->vec4[0][0] = vec[0][0];
			this->vec4[0][1] = vec[0][1];
			this->vec4[0][2] = vec[0][2];
			this->vec4[0][3] = vec[0][3];
		}
		return *this;
	}

	Vec4 operator-(Vec4& ref) {
		if (t == true) {
			this->vec[0][0] = vec4[0][0] - ref.vec4[0][0];
			this->vec[1][0] = vec4[1][0] - ref.vec4[1][0];
			this->vec[2][0] = vec4[2][0] - ref.vec4[2][0];
			this->vec[3][0] = vec4[3][0] - ref.vec4[3][0];

			this->vec4[0][0] = vec[0][0];
			this->vec4[1][0] = vec[1][0];
			this->vec4[2][0] = vec[2][0];
			this->vec4[3][0] = vec[3][0];
		}
		else if (t == false) {
			this->vec[0][0] = vec4[0][0] - ref.vec4[0][0];
			this->vec[0][1] = vec4[0][1] - ref.vec4[0][1];
			this->vec[0][2] = vec4[0][2] - ref.vec4[0][2];
			this->vec[0][3] = vec4[0][3] - ref.vec4[0][3];

			this->vec4[0][0] = vec[0][0];
			this->vec4[0][1] = vec[0][1];
			this->vec4[0][2] = vec[0][2];
			this->vec4[0][3] = vec[0][3];
		}
		return *this;
	}
};