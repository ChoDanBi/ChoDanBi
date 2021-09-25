#include "Enemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "EnemyBridge.h"
//#include "EnemyBullet.h"
#include "Bullet.h"

Enemy::Enemy(): BridgeObject(NULL)
{

}

Enemy::~Enemy()
{
	Release();
}

void Enemy::Initialize() 
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);
	//TransInfo.Scale = ((EnemyBridge*)BridgeObject)->GetScale();

	BridgeObject = NULL;

	HitPoint = 0;
	strKey = "Enemy";
	/*
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(120.0f, 111.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(90.0f, 70.0f);

	Offset = Vector3(0.0f, 0.0f);

	Active = false;
	strKey = "BaseEnemy";
	
	HitPoint = 5;
	Speed = 1.5f;

	Time = GetTickCount64();

	EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
	*/
}

int Enemy::Update()
{
	if (BridgeObject)
		BridgeObject->Update(TransInfo);
	/*
	Collider.Position = Vector3(TransInfo.Position.x,TransInfo.Position.y + 10);

	if (Time + rand() % 2000 + 3000 <= GetTickCount64())
	{
		Time = GetTickCount64();
		EBulletList->push_back(CreateBullet<EnemyBullet>());
	}*/
	return 0;
}

void Enemy::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
	/*
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));*/
	/*
	Ellipse(_hdc,
		Collider.Position.x - Collider.Scale.x / 2,
		Collider.Position.y - Collider.Scale.y / 2,
		Collider.Position.x + Collider.Scale.x / 2,
		Collider.Position.y + Collider.Scale.y / 2 );*/
}

void Enemy::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}