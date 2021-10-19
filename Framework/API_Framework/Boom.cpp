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

	Speed = 10.0f;
	Damage = 10;

	RealObject->SetDamage(Damage);
	RealObject->SetScale(TransInfo.Scale);
	RealObject->SetColliderScale(TransInfo.Scale);

	DrawKey = "Bomb";

	Active = false;

	Frame = 0;
	Time = GetTickCount64();
}

int Boom::Update(Transform& _rTransInfo)
{
	if (_rTransInfo.Position.x >= 1300)
		return 1;

	if (!Active)
	{
		_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
		_rTransInfo.Position.y += _rTransInfo.Direction.y * 0;
	}

	if (Time + 500 < GetTickCount64() && Active)
	{
		Frame++;
		if (Frame == 2)
			RealObject->SetColliderPosition(_rTransInfo.Position.x, _rTransInfo.Position.y);
		else if (Frame == 3)
			RealObject->SetColliderPosition(-100.0f,-100.0f);
			return 1;
	}
	
	RealObject->SetColliderPosition(_rTransInfo.Position.x, _rTransInfo.Position.y);

	//if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		//return 1;

    return 2;
}

void Boom::Render(HDC _hdc)
{
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		int(RealObject->GetScale().x) * Frame,
		0,
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		RGB(255, 0, 255));
}

void Boom::Release()
{
}


