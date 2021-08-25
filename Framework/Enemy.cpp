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
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	Count = 0;
}

int Enemy::Update()
{
	++Count;

	if (Count >= 100)
		return 1;

	return 0;
}

void Enemy::Render()
{
	cout << "Enemy Position : (" << TransInfo.Position.x << ", " << TransInfo.Position.y << ")   Count : " << Count << endl;
}

void Enemy::Release()
{

}
