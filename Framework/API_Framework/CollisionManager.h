#pragma once
#include "Object.h"

class CollisionManager
{
public:
	// ** 구 충돌
	static bool EllipseCollision(Object* _Temp, Object* _Dest)
	{
		// ** 플레이어의 반지름과 Target의 반지름의 합을 구함.
		float Sum = (_Temp->GetScale().x / 2) + (_Dest->GetScale().x / 2);

		// ** 거리를 구하는 공식
		// ** 먼저 기준 Object와 Target Object의 x, y 값을 구함.

		//**    /| 
		//**   / |
		//**  /  | y
		//** /___|
		//**   x
		float fX = _Temp->GetPosition().x - _Dest->GetPosition().x;
		float fY = _Temp->GetPosition().y - _Dest->GetPosition().y;

		// ** sqrt() = 루트함수.
		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;

		return false;
	}
};