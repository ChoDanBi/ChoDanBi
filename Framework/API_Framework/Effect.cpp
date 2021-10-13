#include "Effect.h"

Effect::Effect()
{
}

Effect::~Effect()
{
}

void Effect::Initialize()
{
	Frame = 0;
	strKey = "Effect";

	Time = GetTickCount64();

	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(75.0f,54.0f);

	Active = true;
}

int Effect::Update()
{
	if (Frame >= 3)
	{
		Frame = 0;
		Active = false;
	}

	if (Time + 40 < GetTickCount64())
	{
		Time = GetTickCount64();
		Frame++;
	}

	return 0;
}

void Effect::Render(HDC _hdc)
{
	TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0,
		int(TransInfo.Scale.y) * Frame,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
}

void Effect::Release()
{
}


