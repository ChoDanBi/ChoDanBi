#include "NormalBullat.h"
#include "Object.h"

NormalBullat::NormalBullat()
{
}

NormalBullat::~NormalBullat()
{
}

void NormalBullat::Initialize()
{
	Speed = 3.0f;

	Drawkey = "NormalBullet";
}

int NormalBullat::Update(Transform& _rTransInfo)
{
_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;
	return 0;
}

void NormalBullat::Render(HDC _hdc)
{
	
	Ellipse(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().x / 2)));
		
}

void NormalBullat::Release()
{
}


