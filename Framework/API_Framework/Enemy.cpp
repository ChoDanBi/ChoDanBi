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
	if (BridgeObject)
		BridgeObject->Update(TransInfo);

	if (TransInfo.Position.x <= -1000)
		return 1;

	return 0;
}

void Enemy::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
	
	
	Ellipse(_hdc,
		Collider.Position.x - Collider.Scale.x / 2,
		Collider.Position.y - Collider.Scale.y / 2,
		Collider.Position.x + Collider.Scale.x / 2,
		Collider.Position.y + Collider.Scale.y / 2 );
	

	
}

void Enemy::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}