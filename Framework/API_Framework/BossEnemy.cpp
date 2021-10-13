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

    Speed = float(10);
    HitPoint = 10;

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(443.0f, 434.0f);
    TransInfo.Position = Vector3(-1000.0f,-1000.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 150, TransInfo.Scale.y - 300));


    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BossEnemy::Update(Transform& _rTransInfo)
{

    RealObject->SetColliderPosition(TransInfo.Position.x+50, TransInfo.Position.y + 90);
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
        0, 0,
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