#pragma once
#include "Headers.h"

class MathManager
{
public:
	// ** 거리를 구하는 함수
	static float GetDistance(Vector3 _Current, Vector3 _Target)
	{
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		return sqrt((fX * fX) + (fY * fY));
	}


	// ** 방향을 구하는 함수
	static Vector3 GetDirection(Vector3 _Current, Vector3 _Target)
	{
		float fX = _Target.x - _Current.x;
		float fY = _Target.y - _Current.y;

		float Distance = sqrt((fX * fX) + (fY * fY));

		return Vector3(fX / Distance, fY / Distance);
	}
};

