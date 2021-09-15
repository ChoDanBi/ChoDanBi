#include "Bullet.h"
#include "ObjectManager.h"
#include "MathManager.h"
#include "NormalBullet.h"

Bullet::Bullet() : BridgeObject(NULL)
{

}

Bullet::~Bullet()
{

}


void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(1.0f, 0.0f);
	TransInfo.Scale = Vector3(30.0f, 30.0f);

	BridgeObject = NULL;

	strKey = "Bullet";
	Active = false;

	Speed = 3.0f;

//	Target = ObjectManager::GetInstance()->GetTarget(TransInfo.Position);
}

int Bullet::Update()
{
//	Target = ObjectManager::GetInstance()->GetTarget(TransInfo.Position);

//	if (Target)
//		TransInfo.Direction = MathManager::GetDirection(TransInfo.Position, Target->GetPosition());	

	if (BridgeObject)BridgeObject->Update(TransInfo);

	return 0;
}

void Bullet::Render(HDC _hdc)
{
	if (BridgeObject) BridgeObject->Render(_hdc);
}

void Bullet::Release()
{
	delete BridgeObject;
	BridgeObject = nullptr;
}
