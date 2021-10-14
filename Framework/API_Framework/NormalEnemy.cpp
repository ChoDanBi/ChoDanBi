#include "NormalEnemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

#include "Bullet.h"
#include "EnemyBullet.h"

NormalEnemy::NormalEnemy()
{
}

NormalEnemy::~NormalEnemy()
{
}

void NormalEnemy::Initialize()
{
    DrawKey = "NormalEnemy";
    Speed = 10.0f;
    HitPoint = 5;

    Frame = 0;
    Animation = ANIMATION::UPSWING;
    a_Time = GetTickCount64();

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(150.0f, 200.0f);
    TransInfo.Position = Vector3(0.0f,0.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 70, TransInfo.Scale.y - 160));


    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}


int NormalEnemy::Update(Transform& _rTransInfo)
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

    TransInfo.Position.x -= Speed;

    RealObject->SetColliderPosition(TransInfo.Position.x , TransInfo.Position.y + 5);

    return 0;
}

void NormalEnemy::Render(HDC _hdc)
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

void NormalEnemy::Release()
{
}

