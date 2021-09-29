#include "Menu.h"

#include "SceneManager.h"
#include "InputManager.h"
#include "CollisionManager.h"

#include "Stage_Back.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Initialize()
{	
	click = 0;

	Buttom1.Scale = Vector3(195.0f,70.0f);
	Buttom1.Position = Vector3(900.0f,645.0f);
	

	StageBack = new Stage_Back;
	StageBack->Initialize();
	((Stage_Back*)StageBack)->SetStageState(0);

	ImageList = Object::GetImageList();
}

void Menu::Update()
{
	Transform Mouse;
	
	Mouse.Scale = Vector3(5.0f, 5.0f);
	Mouse.Position = InputManager::GetInstance()->GetMousePosition();
	
	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_LBUTTON)	click = 1;
	else							click = 0;

	if (CollisionManager::RectCollision(Buttom1,Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
	/*
	if (GetAsyncKeyState('S'))
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
*/
}

void Menu::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());

	/*
	Rectangle(_hdc,
		Buttom1.Position.x - Buttom1.Scale.x / 2,
		Buttom1.Position.y - Buttom1.Scale.y / 2,
		Buttom1.Position.x + Buttom1.Scale.x / 2,
		Buttom1.Position.y + Buttom1.Scale.y / 2);
	
	Rectangle(_hdc,
		Mouse.Position.x - Mouse.Scale.x / 2,
		Mouse.Position.y - Mouse.Scale.y / 2,
		Mouse.Position.x + Mouse.Scale.x / 2,
		Mouse.Position.y + Mouse.Scale.y / 2);
*/
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
