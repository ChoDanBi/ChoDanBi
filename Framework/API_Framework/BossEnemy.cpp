#include "BossEnemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "EnemyBullet.h"


BossEnemy::BossEnemy()
{
}

BossEnemy::~BossEnemy()
{
}

void BossEnemy::Initialize()
{
    DrawKey = "BossEnemy";

    Speed = 10;
    HitPoint = 1000;

    Frame = 0;
    Animation = ANIMATION::UPSWING;
    a_Time = GetTickCount64();

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(400.0f, 625.0f);
    TransInfo.Position = Vector3(0.0f,0.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 150, TransInfo.Scale.y - 540));


    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BossEnemy::Update(Transform& _rTransInfo)
{
    if (a_Time + 200 < GetTickCount64())
    {
        a_Time = GetTickCount64();
        switch (Animation)
        {
        case ANIMATION::UPSWING:
            if (Frame <= 1)
                Animation = ANIMATION::DOWNSWING;
            Frame--;
            break;
        case ANIMATION::DOWNSWING:
            if (Frame >= 1)
                Animation = ANIMATION::UPSWING;
            Frame++;
            break;
        }
    }


    TransInfo.Position.y -= Speed;
    TransInfo.Position.y += Speed;


    RealObject->SetColliderPosition(TransInfo.Position.x + 25, TransInfo.Position.y + 20);
    return 0;
}

void BossEnemy::Render(HDC _hdc)
{
    TransparentBlt(_hdc,
        int(TransInfo.Position.x - (TransInfo.Scale.x / 2)),
        int(TransInfo.Position.y - (TransInfo.Scale.y / 2)),
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        ImageList[DrawKey]->GetMemDC(),
        int(TransInfo.Scale.x * Frame),
        0,
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        RGB(255, 0, 255));
}

void BossEnemy::Release()
{
}

template<typename T>
Object* BossEnemy::CreateBullet()
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

    return pBullet;
}