#include "ScoreManager.h"

ScoreManager* ScoreManager::Instance = nullptr;

void ScoreManager::Initialize()
{

}

void ScoreManager::MakeScoreNumber()
{
	Image = (new Bitmap)->LoadBmp(L"../Resource/Number.bmp");

	SetScore(687465415);
	
	stack<int> Numbers;

	while (Score > 0)
	{
		int iTemp = int(Score % 10);
		Score /= 10;

		Numbers.push(iTemp);
	}

	while (!Numbers.empty())
	{
		NumberList.push_back(Numbers.top());
		Numbers.pop();
	}
}

void ScoreManager::Render(HDC _hdc)
{
	/*
	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(0),
		int(0),
		int(64),
		int(85),
		Image->GetMemDC(),
		int(64) * 0,
		int(85) * 0,
		int(64),
		int(85),
		RGB(255, 0, 255));

		TransparentBlt(_hdc,
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		int(TransInfo.Scale.x * Frame),
		int(TransInfo.Scale.y * 0),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));
	*/
	TransparentBlt(_hdc, // ** ���� ��� ��ġ
		int(WindowsWidth/2),
		int(WindowsHeight/2),
		int(350),
		int(75),
		Image->GetMemDC(),
		int(64) * 0,
		int(85) * 0,
		int(350),
		int(75),
		RGB(255, 0, 255));
}
