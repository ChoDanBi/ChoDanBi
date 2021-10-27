#include "SelectStage.h"

#include "Stage_Back.h"
#include "StageButton.h"

#include "SceneManager.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "SoundManager.h"
#include "ObjectManager.h"

SelectStage::SelectStage()
{
}

SelectStage::~SelectStage()
{
}

void SelectStage::Initialize()
{

	click = 0;

	SoundManager::GetInstance()->OnPlaySound("Wait");

	BackButtom.Scale = Vector3(195.0f, 70.0f);
	BackButtom.Position = Vector3(130.0f, 70.0f);

	//	StageButtom1.Scale = Vector3(57.0f, 47.0f);
	//	StageButtom1.Position = Vector3(300.0f, 500.0f);

	StageBack = new Stage_Back;
	StageBack->Initialize();
	((Stage_Back*)StageBack)->SetStageState(1);

	s_SelectButton = ObjectManager::GetInstance()->GetButton();


	ImageList = Object::GetImageList();
}

void SelectStage::Update()
{
	s_SelectButton->Update();

	Transform Mouse;

	Mouse.Scale = Vector3(10.0f, 10.0f);
	Mouse.Position = InputManager::GetInstance()->GetMousePosition();

	if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)  click = 1;
	else							click = 0;

	if (CollisionManager::RectCollision(BackButtom, Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::MENU);

}

void SelectStage::Render(HDC _hdc)
{
	StageBack->Render(ImageList["Buffer"]->GetMemDC());

	s_SelectButton->Render(ImageList["Buffer"]->GetMemDC());
	
/*
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

void SelectStage::Release()
{
}


