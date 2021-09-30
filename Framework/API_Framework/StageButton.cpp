#include "StageButton.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "SceneManager.h"

StageButton::StageButton()
{
}


StageButton::~StageButton()
{
}

void StageButton::Initialize()
{
	//stage1 (57,47) (450,460)

	//stage2 (57,47) (800,470)

	//stage3 (57,47) (975,225)

	//stage4 (57,47) (610,225)

	//stage5 (57,47) (275,220)


	TransInfo.Position = Vector3(450.0f, 460.0f);
	TransInfo.Scale = Vector3(64.0f, 64.0f);

	strKey = "Star";

	for (int i = 0; i < 5; ++i)
		clear[i] = false;

	click = 0;
}

int StageButton::Update()
{
	Transform Mouse;

	Mouse.Scale = Vector3(5.0f, 5.0f);
	Mouse.Position = InputManager::GetInstance()->GetMousePosition();

	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_LBUTTON)	click = 1;
	else							click = 0;

	if (CollisionManager::RectCollision(TransInfo, Mouse) && click == 1)
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE);

	return 0;
}

void StageButton::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x/2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y/2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * clear[0]),
		0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
	/*
	Rectangle(_hdc,
		TransInfo.Position.x - TransInfo.Scale.x / 2,
		TransInfo.Position.y - TransInfo.Scale.y / 2,
		TransInfo.Position.x + TransInfo.Scale.x / 2,
		TransInfo.Position.y + TransInfo.Scale.y / 2);
	*/
}

void StageButton::Release()
{
}


void StageButton::StageClear(int _Clear)
{
	clear[_Clear] = true;
}
