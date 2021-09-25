#include "BaseEnemy.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "EnemyBullet.h"

BaseEnemy::BaseEnemy()
{
}

BaseEnemy::~BaseEnemy()
{
}

void BaseEnemy::Initialize()
{
    DrawKey = "BaseEnemy";

    Speed = 3.0f;
    HitPoint = 3;

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(120.0f, 111.0f);
    TransInfo.Position = Vector3(0.0f, 0.0f);

    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BaseEnemy::Update()
{
    if (Time + rand() % 2000 + 3000 <= GetTickCount64())
    {
        Time = GetTickCount64();
        EBulletList->push_back(CreateBullet<EnemyBullet>());
    }

    return 0;
}

void BaseEnemy::Render(HDC _hdc)
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
    /*
    Ellipse(_hdc,
        Collider.Position.x - Collider.Scale.x / 2,
        Collider.Position.y - Collider.Scale.y / 2,
        Collider.Position.x + Collider.Scale.x / 2,
        Collider.Position.y + Collider.Scale.y / 2 );*/
}

void BaseEnemy::Release()
{
}

template<typename T>
Object* BaseEnemy::CreateBullet()
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge);

    return pBullet;
}