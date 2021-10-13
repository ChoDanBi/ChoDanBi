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

    HitPoint = 3;
    Speed = 2.0f;

    Frame = 0;
    Animation = ANIMATION::UPSWING;
    a_Time = GetTickCount64();

    Time = GetTickCount64();

    TransInfo.Scale = Vector3(125.0f, 150.0f);
    TransInfo.Position = Vector3(0.0f, 0.0f);

   RealObject->SetScale(TransInfo.Scale);
   RealObject->SetHitPoint(HitPoint);
   RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 30, TransInfo.Scale.y - 40));

    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BaseEnemy::Update(Transform& _rTransInfo)
{
    //_rTransInfo = TransInfo; //�̷������� �ѱ�� ��� setter�� �̿��ص� �ȴ�
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
        int(TransInfo.Scale.x * Frame),
        0,
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