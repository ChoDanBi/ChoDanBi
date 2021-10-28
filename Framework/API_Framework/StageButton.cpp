#include "StageButton.h"
#include "InputManager.h"
#include "CollisionManager.h"
#include "SceneManager.h"
#include "SoundManager.h"

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


	TransInfo.Position = Vector3(0.0f,0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	for (int i = 0; i < 5; i++)
	{
		clear[i] = 0;
		ButtonPos[i].Scale = Vector3(64.0f, 64.0f);
	}

	ButtonPos[0].Position = Vector3(450.0f,460.0f);
	ButtonPos[1] .Position= Vector3(800.0f,470.0f + 1024);
	ButtonPos[2].Position = Vector3(975.0f,225.0f +1024);
	ButtonPos[3].Position = Vector3(610.0f,225.0f + 1024);
	ButtonPos[4].Position = Vector3(275.0f,220.0f + 1024);

	strKey = "Star";
	
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

	if (CollisionManager::RectCollision(ButtonPos[0], Mouse) && click == 1)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE4);
		SoundManager::GetInstance()->StopSound("Wait");
		SoundManager::GetInstance()->OnPlaySound("Stage");
	}

	if (CollisionManager::RectCollision(ButtonPos[1], Mouse) && click == 1)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE2);
		SoundManager::GetInstance()->StopSound("Wait");
		SoundManager::GetInstance()->OnPlaySound("Stage");
	}

	if (CollisionManager::RectCollision(ButtonPos[2], Mouse) && click == 1)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE3);
		SoundManager::GetInstance()->StopSound("Wait");
		SoundManager::GetInstance()->OnPlaySound("Stage");
	}

	if (CollisionManager::RectCollision(ButtonPos[3], Mouse) && click == 1)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::STAGE4);
		SoundManager::GetInstance()->StopSound("Wait");
		SoundManager::GetInstance()->OnPlaySound("Boss");
	}

	if (CollisionManager::RectCollision(ButtonPos[4], Mouse) && click == 1)
	{
		SceneManager::GetInstance()->SetScene(SCENEID::END);
		SoundManager::GetInstance()->StopSound("Wait");
		SoundManager::GetInstance()->OnPlaySound("Ending");
	}

	return 0;
}

void StageButton::Render(HDC _hdc)
{
	for (int i = 0; i < 5; i++)
	{
	TransparentBlt(_hdc,
		int(ButtonPos[i].Position.x - (ButtonPos[i].Scale.x/2)),
		int(ButtonPos[i].Position.y - (ButtonPos[i].Scale.y/2) ),
		int(ButtonPos[i].Scale.x),
		int(ButtonPos[i].Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(ButtonPos[i].Scale.x * clear[i]  ),
		0,
		int(ButtonPos[i].Scale.x),
		int(ButtonPos[i].Scale.y),
		RGB(255, 0, 255));
	}
	
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
	for (int i = 0; i < _Clear; i++)
	{
		if (!clear[i])
		{
		clear[i] = true;
		ButtonPos[i + 1].Position.y -= 1024;
		break;
		}
	}
}
