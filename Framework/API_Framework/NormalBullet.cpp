#include "NormalBullet.h"
#include "InventoryManager.h"
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
	TransInfo.Scale = Vector3(15.0f, 30.0f);

	Speed = 8.0f;
	Damage = InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE);
	PatternNumber = 1;

	for (int i = 0; i < 3; i++)
	{
		p_Pattern[i].Direction = Vector3(1.0f, 0.5f * (1 - i));
	}

	RealObject->SetDamage(Damage);
	RealObject->SetScale(TransInfo.Scale);
	RealObject->SetColliderScale(TransInfo.Scale);

	DrawKey = "PBullet";
}

int NormalBullet::Update(Transform& _rTransInfo)
{
	_rTransInfo.Position.x +=Speed;
	_rTransInfo.Position.y += p_Pattern[PatternNumber].Direction.y * Speed;

	RealObject->SetColliderPosition(_rTransInfo.Position.x,_rTransInfo.Position.y);

	return 0;
}


void NormalBullet::Render(HDC _hdc)
{
	
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
		int(RealObject->GetPosition().y - (RealObject->GetScale().y/ 2) ),
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		ImageList[DrawKey]->GetMemDC(),
		int(RealObject->GetScale().x) * 
		(InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE) -1),
		0,
		int(RealObject->GetScale().x),
		int(RealObject->GetScale().y),
		RGB(255, 0, 255));

}

void NormalBullet::Release()
{

}
