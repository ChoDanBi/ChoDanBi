#pragma once
#include "Headers.h"

class MathManager
{
public:
	// ** 거리를 구하는 함수
	static float GetDistance(Vector3 _Current, Vector3 _Target)
	{
		// ** _Current 와 _Target 사이의 밑변과 높이를 구함.
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		// ** 빗변을 반환
		return sqrt((fX * fX) + (fY * fY));
	}

	// ** 방향을 구하는 함수
	static Vector3 GetDirection(Vector3 _Current, Vector3 _Target)
	{
		// ** _Current 와 _Target 사이의 밑변과 높이를 구함.
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		// ** 빗변을 구함.
		float Distance = sqrt((fX * fX) + (fY * fY));

		// ** 방향만 남겨두기 위해 빗변으로 나눠준다.
		return Vector3(fX / Distance, fY / Distance);
		// ** 설명 
		// ** 직각인 삼각형이 있을때 빗변은 항상 밑변이나 높이보다 크다.
		// ** 자기 자신보다 큰값으로 나눠진다면 값은 1보다 작은 값이 나온다.
		// ** Vector 에서 1이거나 1보다 작은 값은 방향만 남아있다고 본다.
		// ** 1 이라는 값에 어떤값을 곱하더라도 같은 값이 나오기 때문이다.
	}
};

