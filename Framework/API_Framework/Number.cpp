#include "Number.h"

void Number::Initialize(Vector3 _vPos, int _Number)
{
	Image = (new Bitmap)->LoadBmp(L"../Resource/Number.bmp");
	TransInfo.Scale = Vector3(35.0f, 75.0f);
	TransInfo.Position = _vPos;
	SetScore(_Number);
}

void Number::MakeScoreNumber(int _Number)
{
	SetScore(_Number);

	stack<int> Numbers;

	if (Score == 0)
		Numbers.push(0);

	while (Score > 0)
	{
		int iTemp = int(Score % 10);
		Score /= 10;

		Numbers.push(iTemp);
	}

	if (!NumberList.empty())
	{
		NumberList.clear();
	}

	while (!Numbers.empty())
	{
		NumberList.push_back(Numbers.top());
		Numbers.pop();
	}
}

void Number::Render(HDC _hdc)
{
	/*
	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(WindowsWidth / 2),
		int(WindowsHeight / 2),
		int(350),
		int(75),
		Image->GetMemDC(),
		int(64) * 0,
		int(85) * 0,
		int(350),
		int(75),
		RGB(255, 0, 255));
	*/
		
	for (int i = 0; i < NumberList.size(); i++)
	{
		TransparentBlt(_hdc, // ** 최종 출력 위치
			int(TransInfo.Position.x - (TransInfo.Scale.x / 2)) + i * int(35),
			int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			Image->GetMemDC(),
			int(TransInfo.Scale.x) * NumberList[i],
			0,
			int(TransInfo.Scale.x),
			int(TransInfo.Scale.y),
			RGB(255, 0, 255));

	}
		
	/*
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
	*/
}