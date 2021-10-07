#include "Shop.h"
#include "Stage_Back.h"

#include "SceneManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "ScoreManager.h"


Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::Initialize()
{
	click = 0;
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
	Transform Mouse;

	Mouse.Scale = Vector3(10.0f, 10.0f);
	Mouse.Position = InputManager::GetInstance()->GetMousePosition();

	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_LBUTTON)	click = 1;
	else							click = 0;

	if (CollisionManager::RectCollision(Buttom[0], Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);
}

void Shop::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());

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


