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

	// ** 구 충돌
	static bool EllipseCollision(const Transform& _Temp, const Transform& _Dest)
	{
		// ** 플레이어의 반지름과 Target의 반지름의 합을 구함.
		float Sum = (_Temp.Scale.x / 2) + (_Dest.Scale.x / 2);

		// ** 거리를 구하는 공식
		// ** 먼저 기준 Object와 Target Object의 x, y 값을 구함.

		//**    /| 
		//**   / |
		//**  /  | y
		//** /___|
		//**   x
		float fX = _Temp.Position.x - _Dest.Position.x;
		float fY = _Temp.Position.y - _Dest.Position.y;

		// ** sqrt() = 루트함수.
		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;

		return false;
	}




	//** vector V1(x, y)
	//**   ↓ 
	//**   |￣￣￣￣| 
	//**   |       |
	//**   |       | 
	//**   |_______| y
	//**         x ↑
	//**         vector V2(x, y)

	static bool RectCollision(Object* V1, Object* V2)
	{
		if ((V1->GetPosition().x + (V1->GetScale().x / 2)) > (V2->GetPosition().x - (V2->GetScale().x / 2)) &&
			(V1->GetPosition().y + (V1->GetScale().y / 2)) > (V2->GetPosition().y - (V2->GetScale().y / 2)) &&
			(V1->GetPosition().x - (V1->GetScale().x / 2)) < (V2->GetPosition().x + (V2->GetScale().x / 2)) &&
			(V1->GetPosition().y - (V1->GetScale().y / 2)) < (V2->GetPosition().y + (V2->GetScale().y / 2)))
			return true;
		return false;
	}

	static bool RectCollision(RECT V1, RECT V2)
	{
		if (V1.left < V2.right && V1.top < V2.bottom &&
			V2.left < V1.right && V2.top < V1.bottom)
			return true;
		return false;
	}
};