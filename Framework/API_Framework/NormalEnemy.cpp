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
    Speed = 8.0f;
    HitPoint = 5;

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(166.0f, 212.0f);
    TransInfo.Position = Vector3(-1000.0f, -1000.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 70, TransInfo.Scale.y - 160));


    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}


int NormalEnemy::Update(Transform& _rTransInfo)
{
    TransInfo.Position.x -= Speed;

    RealObject->SetColliderPosition(TransInfo.Position.x, TransInfo.Position.y - 10);

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
        0, 0,
        int(TransInfo.Scale.x),
        int(TransInfo.Scale.y),
        RGB(255, 0, 255));
}

void NormalEnemy::Release()
{
}

