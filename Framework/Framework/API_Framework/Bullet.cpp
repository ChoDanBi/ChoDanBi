#include "Bullet.h"
#include "ObjectManager.h"
#include "MathManager.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}


void Bullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(30.0f, 30.0f);

	strKey = "Bullet";
	Active = false;

	Speed = 3.0f;

	Target = ObjectManager::GetInstance()->GetTarget(TransInfo.Position);
}

int Bullet::Update()
{
	Target = ObjectManager::GetInstance()->GetTarget(TransInfo.Position);

	if (Target)
	{	
		TransInfo.Direction = MathManager::GetDirection(TransInfo.Position, Target->GetPosition());
	}
		TransInfo.Position.x += TransInfo.Direction.x * Speed;
		TransInfo.Position.y += TransInfo.Direction.y * Speed;


	if (TransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	return 0;
}

void Bullet::Render(HDC _hdc)
{
	Ellipse(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.x + (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y + (TransInfo.Scale.x / 2)));
}

void Bullet::Release()
{

}
