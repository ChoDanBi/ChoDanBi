#include "Shop.h"
#include "Stage_Back.h"
#include "StateBar.h"

#include "SceneManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "ScoreManager.h"
#include "InventoryManager.h"

Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Initialize()
{
	click = 0;


	State = new StateBar;
	State->Initialize();

	StageBack = new Stage_Back;
	StageBack->Initialize();
	((Stage_Back*)StageBack)->SetStageState(6);

	Buttom[0].Scale = Vector3(330.0f, 100.0f);
	Buttom[0].Position = Vector3(1080.0f, 60.0f);

	Buttom[1].Scale = Vector3(330.0f, 100.0f);
	Buttom[1].Position = Vector3(380.0f, 500.0f);

	Buttom[2].Scale = Vector3(330.0f, 100.0f);
	Buttom[2].Position = Vector3(890.0f, 500.0f);

	Buttom[3].Scale = Vector3(330.0f, 100.0f);
	Buttom[3].Position = Vector3(890.0f, 250.0f);

	Buttom[4].Scale = Vector3(330.0f, 100.0f);
	Buttom[4].Position = Vector3(380.0f, 250.0f);

	// 4 3
	// 1 2

	ImageList = Object::GetImageList();
}

void Shop::Update()
{
	ScoreManager::GetInstance()->MakeScoreNumber();


	Transform Mouse;

	Mouse.Scale = Vector3(10.0f, 10.0f);
	Mouse.Position = InputManager::GetInstance()->GetMousePosition();

	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001 )  click = 1;
	else							click = 0;

	if (CollisionManager::RectCollision(Buttom[0], Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

	// 4 3
	// 1 2

	if (CollisionManager::RectCollision(Buttom[4], Mouse) && click == 1)
	{
		if (InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE) < 6
			&& InventoryManager::GetInstance()->GetItem(INVENTORY::GOLD) >= InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE) * 3)
		{
			InventoryManager::GetInstance()->UseItem(INVENTORY::GOLD, InventoryManager::GetInstance()->GetItem(INVENTORY::DAMAGE) * 3);
			InventoryManager::GetInstance()->AddItem(INVENTORY::DAMAGE);
		}
	}
	if (CollisionManager::RectCollision(Buttom[3], Mouse) && click == 1)
	{
		if (InventoryManager::GetInstance()->GetItem(INVENTORY::SPEED)  <  7
			&& InventoryManager::GetInstance()->GetItem(INVENTORY::GOLD) >= InventoryManager::GetInstance()->GetItem(INVENTORY::SPEED))
		{
			InventoryManager::GetInstance()->UseItem(INVENTORY::GOLD, InventoryManager::GetInstance()->GetItem(INVENTORY::SPEED) );
			InventoryManager::GetInstance()->AddItem(INVENTORY::SPEED); //스피드 받음
		}
	}
	if (CollisionManager::RectCollision(Buttom[1], Mouse) && click == 1
		&& InventoryManager::GetInstance()->GetItem(INVENTORY::GOLD) >= 10)
	{
			InventoryManager::GetInstance()->UseItem(INVENTORY::GOLD, 10);
			InventoryManager::GetInstance()->AddItem(INVENTORY::BOMB);
	}
	if (CollisionManager::RectCollision(Buttom[2], Mouse) && click == 1
		&& InventoryManager::GetInstance()->GetItem(INVENTORY::GOLD) >= 10)
	{
			InventoryManager::GetInstance()->UseItem(INVENTORY::GOLD, 10);
			InventoryManager::GetInstance()->AddItem(INVENTORY::SHIELD);
	}


}

void Shop::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());
	/*
	for (int i = 0; i < 4; i++)
	{

	Rectangle(_hdc,
		Buttom[i].Position.x - Buttom[i].Scale.x / 2,
		Buttom[i].Position.y - Buttom[i].Scale.y / 2,
		Buttom[i].Position.x + Buttom[i].Scale.x / 2,
		Buttom[i].Position.y + Buttom[i].Scale.y / 2);
	}
	*/

	State->Render(ImageList["Buffer"]->GetMemDC());

	ScoreManager::GetInstance()->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Shop::Release()
{
}


