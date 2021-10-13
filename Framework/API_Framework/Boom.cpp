#include "Boom.h"
#include "Object.h"

Boom::Boom()
{
}

Boom::~Boom()
{
}

void Boom::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(100.0f, 124.0f);

	Speed = 8.0f;
	Damage = 20;

	RealObject->SetDamage(Damage);
	RealObject->SetScale(TransInfo.Scale);
	RealObject->SetColliderScale(TransInfo.Scale);

	DrawKey = "Bomb";

	Frame = 0;
	Time = GetTickCount64();
}

int Boom::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * 0;

	//RealObject->SetColliderPosition(_rTransInfo.Position.x, _rTransInfo.Position.y);

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

    return 2;
}

void Boom::Render(HDC _hdc)
{
}

void Boom::Release()
{
}


