#include "StateBar.h"
#include "InventoryManager.h"

StateBar::StateBar()
{
}

StateBar::~StateBar()
{
}

void StateBar::Initialize()
{
	strKey = "Bar";
	for (int i = 0; i < 2; i++)
	{
		TransInform[i].Scale = Vector3(525.0f,75.0f);
		TransInform[i].Position = Vector3(370.0f + 580*i,380.0f);
	}
}

int StateBar::Update()
{




	return 0;
}

void StateBar::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInform[0].Position.x - (TransInform[0].Scale.x / 2)),
		int(TransInform[0].Position.y - (TransInform[0].Scale.y / 2)),
		int(TransInform[0].Scale.x),
		int(TransInform[0].Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,
		75 *(6 - 
			InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE)),
		int(TransInform[0].Scale.x),
		int(TransInform[0].Scale.y),
		RGB(255, 0, 255));

	TransparentBlt(_hdc,
		int(TransInform[1].Position.x - (TransInform[1].Scale.x / 2)),
		int(TransInform[1].Position.y - (TransInform[1].Scale.y / 2)),
		int(TransInform[1].Scale.x),
		int(TransInform[1].Scale.y),
		ImageList[strKey]->GetMemDC(),
		0, 
		75 *(6 - 
			(InventoryManager::GetInstance()->GetItem(INVENTORY::SPEED)-1)),
		int(TransInform[1].Scale.x),
		int(TransInform[1].Scale.y),
		RGB(255, 0, 255));
}

void StateBar::Release()
{

}

