#include "ScoreManager.h"
#include "InventoryManager.h"

ScoreManager* ScoreManager::Instance = nullptr;

void ScoreManager::Initialize()
{

}

void ScoreManager::MakeScoreNumber()
{
	Image = (new Bitmap)->LoadBmp(L"../Resource/Number.bmp");

	SetScore(InventoryManager::GetInstance()->GetItem(INVENTORY::GOLD));
	
	stack<int> Numbers;

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

void ScoreManager::Render(HDC _hdc)
{
	for (int i = 0; i < NumberList.size(); i++)
	{
		TransparentBlt(_hdc, // ** 최종 출력 위치
			int(740) + i * int(35),
			int(40),
			int(35),
			int(75),
			Image->GetMemDC(),
			int(35) * NumberList[i],
			int(75) * 0,
			int(35),
			int(75),
			RGB(255, 0, 255));
	}

	/*
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

	TransparentBlt(_hdc, // ** 최종 출력 위치
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
	*/
}
