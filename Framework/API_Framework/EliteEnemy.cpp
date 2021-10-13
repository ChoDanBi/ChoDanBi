#include "EliteEnemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "EnemyBullet.h"

EliteEnemy::EliteEnemy()
{
}

EliteEnemy::~EliteEnemy()
{
}

void EliteEnemy::Initialize()
{
    DrawKey = "EliteEnemy";

    Speed = 3.0f;
    HitPoint = 9;

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(212.0f, 162.0f);
    TransInfo.Position = Vector3(-1000.0f, -1000.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 70, TransInfo.Scale.y - 100));

    MTime = GetTickCount64();
    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
    Move = 2;
}

int EliteEnemy::Update(Transform& _rTransInfo)
{
    if (TransInfo.Position.y < 0)
        TransInfo.Position.y += Speed;
    else if (TransInfo.Position.y > 720)
        TransInfo.Position.y -= Speed;

    if (MTime + rand() % 4000 + 1000 < GetTickCount64())
    {
        MTime = GetTickCount64();
        Move = rand() % 2 + 0;
    }

    switch (Move)
    {
    case 0:
        TransInfo.Position.y -= Speed;
        break;
    case 1:
        TransInfo.Position.y += Speed;
        break;
    case 2:
        TransInfo.Position.y += 0;
        break;
    }

    if (Time + 1500 <= GetTickCount64())
    {
        Time = GetTickCount64();
       for (int i = 0; i < 3; i++)
         EBulletList->push_back(CreateBullet<EnemyBullet>(i));
    }


    TransInfo.Position.x -= Speed;
    RealObject->SetColliderPosition(TransInfo.Position.x, TransInfo.Position.y + 30);

    return 0;
}

void EliteEnemy::Render(HDC _hdc)
{
    TransparentBlt(_hdc,
        int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
        int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        ImageList[DrawKey]->GetMemDC(),
        0, 0,
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        RGB(255, 0, 255));
}

void EliteEnemy::Release()
{
}

template<typename T>
Object* EliteEnemy::CreateBullet(int _Pattern)
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge,_Pattern);

    return pBullet;
}