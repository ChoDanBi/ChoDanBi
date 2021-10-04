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

    Speed = 4.0f;
    HitPoint = 9;

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(212.0f, 162.0f);
    TransInfo.Position = Vector3(0.0f, 0.0f);

    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetHitPoint(HitPoint);
    RealObject->SetCollider(Vector3(TransInfo.Scale.x - 30, TransInfo.Scale.y - 40));


    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int EliteEnemy::Update(Transform& _rTransInfo)
{
    if (Time + 1000 <= GetTickCount64())
    {
        Time = GetTickCount64();
        EBulletList->push_back(CreateBullet<EnemyBullet>());
    }

    TransInfo.Position.x -= Speed;
    RealObject->SetColliderPosition(TransInfo.Position.x, TransInfo.Position.y + 10);

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
Object* EliteEnemy::CreateBullet()
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

    return pBullet;
}