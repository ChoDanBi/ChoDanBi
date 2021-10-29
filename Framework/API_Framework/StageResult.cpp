#include "StageResult.h"

#include "InputManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "CollisionManager.h"

StageResult::StageResult()
{
}

StageResult::~StageResult()
{
}

void StageResult::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2,-587.0f);
	TransInfo.Scale = Vector3(759.0f,587.0f);

	for (int i = 0; i < 2; i++)
	{
		Buttom[i].Scale = Vector3(280.0f, 90.0f);
		Buttom[i].Position = Vector3(float(460 + 370 * i),590.0f);
	}

	Soundplaytime = 0;
	StageNumber = 0;
	Click = 0;
	Clear = false;
}

int StageResult::Update()
{
	if (TransInfo.Position.y >= WindowsHeight / 2)
		TransInfo.Position.y = WindowsHeight / 2;
	else TransInfo.Position.y += 20;

		Transform Mouse;

		Mouse.Scale = Vector3(5.0f, 5.0f);
		Mouse.Position = InputManager::GetInstance()->GetMousePosition();

		if (GetAsyncKeyState(VK_LBUTTON) & 0x0001)  Click = 1;
		else							Click = 0;

		if (Clear)
		{
			if (Soundplaytime == 0)
			{
				SoundManager::GetInstance()->OnPlaySound("Clear");
				Soundplaytime++;
			}
			if (CollisionManager::RectCollision(Buttom[0], Mouse) && Click == 1)
			{
				SoundManager::GetInstance()->StopSound("Stage");
				SoundManager::GetInstance()->StopSound("Boss");
				SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
			}

		if (CollisionManager::RectCollision(Buttom[1], Mouse) && Click == 1)
		{
				SoundManager::GetInstance()->StopSound("Stage");
				SoundManager::GetInstance()->StopSound("Boss");
			switch (StageNumber)
			{
			case 1:
				SceneManager::GetInstance()->SetScene(SCENEID::STAGE2);
				break;
			case 2:
				SceneManager::GetInstance()->SetScene(SCENEID::STAGE3);
				break;
			case 3:
				SceneManager::GetInstance()->SetScene(SCENEID::STAGE4);
				break;
			case 4:
				SceneManager::GetInstance()->SetScene(SCENEID::END);
				break;
			}
		}
	}
	else if (!Clear)
	{
		SoundManager::GetInstance()->StopSound("Stage");
		SoundManager::GetInstance()->StopSound("Boss");
		if(GetAsyncKeyState(' ') & 0x0001)
			SceneManager::GetInstance()->SetScene(SCENEID::SELECTSTAGE);
	}



	return 0;
}

void StageResult::Render(HDC _hdc)
{
	if (Clear)
	{
		TransparentBlt(_hdc,
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			ImageList["Clear"]->GetMemDC(),
			0, 0,
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			RGB(255, 0, 255));

		/*
		for (int i = 0; i < 2; i++)
			Rectangle(_hdc,
				Buttom[i].Position.x - Buttom[i].Scale.x / 2,
				Buttom[i].Position.y - Buttom[i].Scale.y / 2,
				Buttom[i].Position.x + Buttom[i].Scale.x / 2,
				Buttom[i].Position.y + Buttom[i].Scale.y / 2);
		*/
	}
	else if (!Clear)
	{
		TransparentBlt(_hdc,
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			ImageList["Over"]->GetMemDC(),
			0, 0,
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			RGB(255, 0, 255));
	}
}

void StageResult::Release()
{
	
}

