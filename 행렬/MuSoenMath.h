#pragma once
#include <iostream>
using namespace std;

class Vec3
{
private :
	

public :
	float v[1][3] =                  //백터 만들기
	{
		{2,2,1}
	}; 
	float a[1][3];                  //Translate과 곱한 백터 값을 넣을 배열
	float b[1][3];                  //Rotate와 곱한 백터 값을 넣을 배열
	float c[1][3];                  //Scale과 곱한 백터 값을 넣을 배열

};

class Mat3
{
	
public:
	float Translate[3][3] = {                        //이동행렬 구현 (값은 지정)
		{1, 0, 0},
		{0, 1, 0},
		{3, 5, 1}
	};

	float Scale[3][3] = {                           //크기변환 행렬 구현(값 지정)
		{2, 0, 0},
		{0, 2, 0},
		{0, 0, 1} 
	};

	float Rotate[3][3] = {                           //회전행렬 구현(값 지정)
		{0.15,-0.5, 0},
		{0.5,0.15, 0},
		{0, 0, 1}
	};
private:

};
Vec3 vec;       //함수에서 사용할 백터 선언
Mat3 mat;       //함수에서 사용할 매트릭스

void operate()
{
	for (int i = 0; i < 1; i++) {
			for (int k = 0; k < 3; k++) {
				for (int j = 0; j < 3; j++) {
					vec.a[i][k] += vec.v[i][j] * mat.Translate[j][k];           //포문을 사용하여 계산한 값을 넣을 백터 (0,0)부터 시작하여 →↓순으로 곱해주면서 차례대로 a에 더하여 대입해줌
				}
			}
	}
	/*--------------------------------------------------------------*/
	for (int i = 0; i < 1; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				vec.b[i][k] += vec.a[i][j] * mat.Rotate[j][k];
			}                                                                    //이동행렬과 동일
		} 
	}
	//----------------------------------------------------------------
	for (int i = 0; i < 1; i++) {
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				vec.c[i][k] += vec.b[i][j] * mat.Scale[j][k];
			}                                                                    //회전행렬과 동일
		}
	}
	//----------------------------------------------------------------
	cout << "Vec3 p의 좌표 : \n";
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "{" << vec.c[i][j] << "}";                                    //백터 좌표를 출력해주는 코드
		}
		cout << "   ";
	}
}