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
	BridgeObject->SetActive(Active);

	if (TransInfo.Position.x >= 1400 || TransInfo.Position.x <= -100)
		return 1;

	if (BridgeObject)
	{
		int Result = BridgeObject->Update(TransInfo);
		return Result;
	}


	return 0;
}

void Bullet::Render(HDC _hdc)
{
	if (BridgeObject)
		BridgeObject->Render(_hdc);

	Ellipse(_hdc,
		Collider.Position.x - Collider.Scale.x / 2,
		Collider.Position.y - Collider.Scale.y / 2,
		Collider.Position.x + Collider.Scale.x / 2,
		Collider.Position.y + Collider.Scale.y / 2);

}

void Bullet::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}
