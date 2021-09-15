#include "UpBullet.h"
#include "Object.h"

UpBullet::UpBullet()
{
}

UpBullet::~UpBullet()
{
}

void UpBullet::Initialize()
{
	Speed = 3.0f;
	Damage = 2.0f;

	DrawKey = "UpBullet";
}

int UpBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

    return 0;
}

void UpBullet::Render(HDC _hdc)
{
	Rectangle(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
}

void UpBullet::Release()
{
}


