#pragma once
#include "Object.h"

class CollisionManager
{
public:
	// ** �� �浹
	static bool EllipseCollision(Object* _Temp, Object* _Dest)
	{
		// ** �÷��̾��� �������� Target�� �������� ���� ����.
		float Sum = (_Temp->GetScale().x / 2) + (_Dest->GetScale().x / 2);

		// ** �Ÿ��� ���ϴ� ����
		// ** ���� ���� Object�� Target Object�� x, y ���� ����.

		//**    /| 
		//**   / |
		//**  /  | y
		//** /___|
		//**   x
		float fX = _Temp->GetPosition().x - _Dest->GetPosition().x;
		float fY = _Temp->GetPosition().y - _Dest->GetPosition().y;

		// ** sqrt() = ��Ʈ�Լ�.
		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;

		return false;
	}

	// ** �� �浹
	static bool EllipseCollision(const Transform& _Temp, const Transform& _Dest)
	{
		// ** �÷��̾��� �������� Target�� �������� ���� ����.
		float Sum = (_Temp.Scale.x / 2) + (_Dest.Scale.x / 2);

		// ** �Ÿ��� ���ϴ� ����
		// ** ���� ���� Object�� Target Object�� x, y ���� ����.

		//**    /| 
		//**   / |
		//**  /  | y
		//** /___|
		//**   x
		float fX = _Temp.Position.x - _Dest.Position.x;
		float fY = _Temp.Position.y - _Dest.Position.y;

		// ** sqrt() = ��Ʈ�Լ�.
		float Distance = sqrt((fX * fX) + (fY * fY));

		if (Sum > Distance)
			return true;

		return false;
	}




	//** vector V1(x, y)
	//**   �� 
	//**   |��������| 
	//**   |       |
	//**   |       | 7
	//**   |_______| y
	//**         x ��
	//**         vector V2(x, y)

	static bool RectCollision(Transform V1, Transform V2)
	{
		if ((V1.Position.x + (V1.Scale.x / 2)) > (V2.Position.x - (V2.Scale.x / 2)) &&
			(V1.Position.y + (V1.Scale.y / 2)) > (V2.Position.y - (V2.Scale.y / 2)) &&
			(V1.Position.x - (V1.Scale.x / 2)) < (V2.Position.x + (V2.Scale.x / 2)) &&
			(V1.Position.y - (V1.Scale.y / 2)) < (V2.Position.y + (V2.Scale.y / 2)))
			return true;
		return false;
	}

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
			V2.left < V1.right && V2.top < V1.bottom )
			return true;
		return false;
	}
};