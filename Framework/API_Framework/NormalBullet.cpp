#include "NormalBullet.h"
#include "Object.h"

NormalBullet::NormalBullet()
{

}

NormalBullet::~NormalBullet()
{

}


void NormalBullet::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(15.0f, 12.0f);

	Speed = 8.0f;
	Damage = 1;

	RealObject->SetDamage(Damage);
	RealObject->SetScale(TransInfo.Scale);
	RealObject->SetCollider(TransInfo.Scale);

	DrawKey = "PBullet";
}

int NormalBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
	_rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

	RealObject->SetColliderPosition(_rTransInfo.Position.x,_rTransInfo.Position.y);

	if (_rTransInfo.Position.x >= (WindowsWidth - 100))
		return 1;

	

	return 0;
}


void NormalBullet::Render(HDC _hdc)
{
	//여기에 이미지를 출력해야함
	
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y/ 2) ),
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		0, 0,
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		RGB(255, 0, 255));
	
	/*
	Ellipse(_hdc,
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
		int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
*/
}

void NormalBullet::Release()
{

}
