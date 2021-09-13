#include "EnemyHole.h"
#include "Enemy.h"

EnemyHole::EnemyHole()
{
}

EnemyHole::~EnemyHole()
{
}

void EnemyHole::Initialize()
{
	TransInfo.Position = Vector3(0.0f, 0.0f);
	TransInfo.Scale = Vector3(149.0f, 124.0f);

	Collider.Position = Vector3(0.0f, 0.0f);
	Collider.Scale = Vector3(100.0f, 100.0f);

	Offset = Vector3(149.0f, 0.0f);

	State = STATE::DOWNSTAY;

	Active = false;
	strKey = "Hole";

	Speed = 0.0f;

	EnemyMole = new Enemy;
	EnemyMole->Initialize();

	
}

int EnemyHole::Update()
{
	EnemyMole->SetPosition
	(
		TransInfo.Position.x,
		TransInfo.Position.y
	);
	EnemyMole->Update();
	return 0;
}

void EnemyHole::Render(HDC _hdc)
{

	TransparentBlt(_hdc, // ** 최종 출력 위치
		int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
		int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		ImageList[strKey]->GetMemDC(),
		0, 0,
		int(TransInfo.Scale.x),
		int(TransInfo.Scale.y),
		RGB(255, 0, 255));

	EnemyMole->Render(_hdc);
}

void EnemyHole::Release()
{
}

