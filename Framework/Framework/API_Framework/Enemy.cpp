#include "Enemy.h"


Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(100.0f, 100.0f);

	Active = false;

	Speed = 1.5f;
}

int Enemy::Update()
{
	TransInfo.Position.x -= Speed;

	if (TransInfo.Position.x <= 100)
		return 1;
	
	return 0;
}

void Enemy::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2)));
}

void Enemy::Release()
{

}
