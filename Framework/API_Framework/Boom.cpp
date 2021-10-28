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
	RealObject->SetColliderScale(Vector3(68.0f,70.0f));

	DrawKey = "Bomb";

	Active = true;

	Frame[0] = 0;
	Frame[1] = 0;
	Time = GetTickCount64();
}

int Boom::Update(Transform& _rTransInfo)
{
	if (_rTransInfo.Position.x >= 1300)
		return 1;

	if (Active)
	{
		_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
		_rTransInfo.Position.y += _rTransInfo.Direction.y * 0;
		RealObject->SetColliderPosition(_rTransInfo.Position.x + 6, _rTransInfo.Position.y + 21);

		if (Time + 70 < GetTickCount64())
		{
			Time = GetTickCount64();
			Frame[0]++;
			if (Frame[0] == 4)
				Frame[0] = 0;
		}

		return 2;
	}
	else
	{
		if (Time + 70 < GetTickCount64())
		{
			Time = GetTickCount64();
			Frame[1]++;
			if (Frame[1] == 1)
				RealObject->SetColliderPosition(-100.0f, -100.0f);
			else if (Frame[1] == 4)
				return 1;
		}
	}
}

void Boom::Render(HDC _hdc)
{
	if (!Active)
		TransparentBlt(_hdc, // ** 최종 출력 위치
			int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
			int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
			int(RealObject->GetScale().x),
			int(RealObject->GetScale().y),
			ImageList[DrawKey]->GetMemDC(),
			int(RealObject->GetScale().x) * Frame[1],
			0,
			int(RealObject->GetScale().x),
			int(RealObject->GetScale().y),
			RGB(255, 0, 255));
	else
		TransparentBlt(_hdc, // ** 최종 출력 위치
			int(RealObject->GetPosition().x - (124 / 2)),
			int(RealObject->GetPosition().y - (124 / 2)),
			124,
			124,
			ImageList["TBomb"]->GetMemDC(),
			124 * Frame[0],
			0,
			124,
			124,
			RGB(255, 0, 255));
}

void Boom::Release()
{
}


