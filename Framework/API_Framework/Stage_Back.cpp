#include "Stage_Back.h"

Stage_Back::Stage_Back()
{

}

Stage_Back::~Stage_Back()
{

}


void Stage_Back::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Direction = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(0.0f, 0.0f);

	StageState = 0;

	m_strKey[0] = "Stay";
	m_strKey[1] = "Select";
	m_strKey[2] = "Stage1";
	m_strKey[3] = "Stage2";
	m_strKey[4] = "Stage3";
	m_strKey[5] = "Stage4";

	Active = false;
}

int Stage_Back::Update()
{

	return 0;
}

void Stage_Back::Render(HDC _hdc)
{
	BitBlt(_hdc,
		0, 0,
		WindowsWidth,
		WindowsHeight,
		ImageList[m_strKey[StageState]]->GetMemDC(),
		0, 20,
		SRCCOPY);
}

void Stage_Back::Release()
{

}

