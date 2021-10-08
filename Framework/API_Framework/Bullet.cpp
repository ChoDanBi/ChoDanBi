#include "Bullet.h"
#include "ObjectManager.h"
#include "MathManager.h"
#include "NormalBullet.h"

Bullet::Bullet() : BridgeObject(NULL)
{

}

Bullet::~Bullet()
{
	Release();
}


void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(1.0f, 1.0f);
	TransInfo.Scale = Vector3(30.0f, 30.0f);

	BridgeObject = NULL;
	Damage = 0;

	strKey = "Bullet";
	Active = false;
}

int Bullet::Update()
{
	if (BridgeObject)
		BridgeObject->Update(TransInfo);

	if (TransInfo.Position.x >= 2000 || TransInfo.Position.x <= -2000
		|| TransInfo.Position.y >= 2000 || TransInfo.Position.y <= -2000)
		return 1;

	return 0;
}

void Bullet::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);
}

void Bullet::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}
