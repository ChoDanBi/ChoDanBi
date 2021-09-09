#include "Enemy.h"


Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{
	tick = GetTickCount64();

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(149.0f, 124.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(100.0f, 100.0f);

	Offset = Vector3(149.0f, 0.0f);

	Active = false;
	strKey = "Mole";
	
	Speed = 1.5f;
}

int Enemy::Update()
{
	if (tick + rand()% 6000 + 500 < GetTickCount64())
	if( !(Offset.y >= 94) )
		Offset.y += 2.5f;

	return 0;
}

void Enemy::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList["Hole"]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2) - Offset.y - 50),
		int(TransInfo.Scale.x),
		int(Offset.y),
		ImageList[strKey]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(Offset.y),
		RGB(255, 0, 255));

	/*Ellipse(_hdc,
		int(Collider.Position.x - (Collider.Scale.x / 2)),
		int(Collider.Position.y + (Collider.Scale.y / 2) - Offset.y),
		int(Collider.Position.x + (Collider.Scale.x / 2)),
		int(Collider.Position.y + (Collider.Scale.y / 2)));*/
}

void Enemy::Release()
{

}
