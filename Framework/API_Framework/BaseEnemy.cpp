#include "BaseEnemy.h"

#include "ObjectManager.h"
#include "ObjectFactory.h"

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

    Speed = 2.0f;
    HitPoint = 3;

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(120.0f, 111.0f);
    TransInfo.Position = Vector3(-1000.0f, -1000.0f);

   RealObject->SetScale(TransInfo.Scale);
   RealObject->SetHitPoint(HitPoint);
   RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 30, TransInfo.Scale.y - 40));

    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BaseEnemy::Update(Transform& _rTransInfo)
{
    //_rTransInfo = TransInfo; //이런식으로 넘기는 대신 setter을 이용해도 된다
    

    if (Time + rand() % 1000 + 3000 <= GetTickCount64())
    {
        Time = GetTickCount64();
        EBulletList->push_back(CreateBullet<EnemyBullet>());
    }

    TransInfo.Position.x -= Speed;
    RealObject->SetColliderPosition(TransInfo.Position.x, TransInfo.Position.y +10);

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
}

void BaseEnemy::Release()
{
}

template<typename T>
Object* BaseEnemy::CreateBullet()
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge,1);

    return pBullet;
}