#include "StageResult.h"

StageResult::StageResult()
{
}

StageResult::~StageResult()
{
}

void StageResult::Initialize()
{
	TransInfo.Position = Vector3(WindowsWidth / 2, WindowsHeight / 2);
	TransInfo.Scale = Vector3(759.0f,587.0f);

	for (int i = 0; i < 2; i++)
	{
		Buttom[i].Scale = Vector3(195.0f, 70.0f);
		Buttom[i].Position = Vector3(400 + 200 * i,200);
	}

	Clear = false;
}

int StageResult::Update()
{
	if (Clear)
	{

	}
	else if (!Clear)
	{

	}

	return 0;
}

void StageResult::Render(HDC _hdc)
{
	if (Clear)
	{

	}
	else if (!Clear)
	{

	}
}

void StageResult::Release()
{
}

