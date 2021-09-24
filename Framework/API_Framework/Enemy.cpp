#include "Enemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "EnemyBullet.h"
#include "Bullet.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{

}

void Enemy::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(164.0f, 153.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(130.0f, 130.0f);

	Offset = Vector3(0.0f, 0.0f);

	Active = false;
	strKey = "Enemy_1";
	
	HitPoint = 5;
	Speed = 1.5f;

	Time = GetTickCount64();

	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int Enemy::Update()
{
	Collider.Position = TransInfo.Position;

	if (Time + rand() % 2000 + 3000 <= GetTickCount64())
	{
		Time = GetTickCount64();
		EBulletList->push_back(CreateBullet<EnemyBullet>());
	}
	return 0;
}

void Enemy::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	Ellipse(_hdc,
		Collider.Position.x - Collider.Scale.x / 2,
		Collider.Position.y - Collider.Scale.y / 2,
		Collider.Position.x + Collider.Scale.x / 2,
		Collider.Position.y + Collider.Scale.y / 2);
}

void Enemy::Release()
{

}

template<typename T>
Object* Enemy::CreateBullet()
{
	Bridge* pBridge = new T;

	Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

	return pBullet;
}