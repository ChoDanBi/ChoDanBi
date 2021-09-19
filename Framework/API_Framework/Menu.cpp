#include "Menu.h"

#include "SceneManager.h"

#include "Stage_Back.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Initialize()
{
	StageBack = new Stage_Back;
	StageBack->Initialize();

	ImageList = Object::GetImageList();
}

void Menu::Update()
{
	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);
}

void Menu::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());
	//State_Back->Render(ImageList["Buffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList["Buffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);
}

void Menu::Release()
{

}
