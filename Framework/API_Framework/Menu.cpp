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

	for (int i = 0; i < 2; i++)
	{
	Buttom[i].Scale = Vector3(195.0f,70.0f);
	Buttom[i].Position = Vector3(900.0f - i * 230,645.0f);
	}
	

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
	
	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)  click = 1;
	else							click = 0;

	if (CollisionManager::RectCollision(Buttom[0],Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
	if (CollisionManager::RectCollision(Buttom[1], Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::SHOP);
}

void Menu::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());

	/*
	Rectangle(_hdc,
		Buttom[1].Position.x - Buttom[1].Scale.x / 2,
		Buttom[1].Position.y - Buttom[1].Scale.y / 2,
		Buttom[1].Position.x + Buttom[1].Scale.x / 2,
		Buttom[1].Position.y + Buttom[1].Scale.y / 2);
	
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
