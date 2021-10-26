#include "Ending.h"
#include "Stage_Back.h"

#include "ObjectManager.h"
#include "SceneManager.h"
#include "InputManager.h"

Ending::Ending()
{
}

Ending::~Ending()
{
}

void Ending::Initialize()
{
	StageBack = new Stage_Back;
	StageBack->Initialize();
	((Stage_Back*)StageBack)->SetStageState(1);

	ImageList = Object::GetImageList();
	Image = (new Bitmap)->LoadBmp(L"../Resource/End.bmp");
	TransInfo.Position = Vector3(1280.0f, 720.0f);
	TransInfo.Scale = Vector3(1280.0f, 720.0f);
}

void Ending::Update()
{
	Transform Mouse;

	Mouse.Scale = Vector3(5.0f, 5.0f);
	Mouse.Position = Vector3(5.0f, 5.0f);

	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_LBUTTON & 0x0001)
		SceneManager::GetInstance()->SetScene(SCENEID::EXIT);
}

void Ending::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		Image->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Ending::Release()
{
}


