#include "Enemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "EnemyBridge.h"
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
	TransInfo.Position = Vector3(-1000.0f, -1000.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	BridgeObject = NULL;

	HitPoint = 3;
	strKey = "Enemy";
}

int Enemy::Update()
{
	BridgeObject->SetActive(Active);

	if (TransInfo.Position.x <= -1000)
		return 1;

	if (BridgeObject)
	{
		int Result = BridgeObject->Update(TransInfo);
		return Result;
	}


	return 0;
}

void Enemy::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
	
	/*
	Ellipse(_hdc,
		int(Collider.Position.x - Collider.Scale.x / 2),
		int(Collider.Position.y - Collider.Scale.y / 2),
		int(Collider.Position.x + Collider.Scale.x / 2),
		int(Collider.Position.y + Collider.Scale.y / 2) );
	*/	
}

void Enemy::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}