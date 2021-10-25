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
   RealObject->SetColliderScale(Vector3(TransInfo.Scale.x - 50, TransInfo.Scale.y -100));

    EBulletList = ObjectManager::GetInstance()->GetEnemyBullet();
}

int BaseEnemy::Update(Transform& _rTransInfo)
{
    //_rTransInfo = TransInfo; //이런식으로 넘기는 대신 setter을 이용해도 된다
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

    _rTransInfo.Position.x -= Speed;
    RealObject->SetColliderPosition(_rTransInfo.Position.x-10, _rTransInfo.Position.y+10);

    return 0;
}

void BaseEnemy::Render(HDC _hdc)
{
    /*
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
    */
    TransparentBlt(_hdc, // ** 최종 출력 위치
        int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
        int(RealObject->GetScale().x),
        int(RealObject->GetScale().y),
        ImageList[DrawKey]->GetMemDC(),
        int(RealObject->GetScale().x) * Frame, 0,
        int(RealObject->GetScale().x),
        int(RealObject->GetScale().y),
        RGB(255, 0, 255));
}

void BaseEnemy::Release()
{
}

template<typename T>
Object* BaseEnemy::CreateBullet()
{
    Bridge* pBridge = new T;

    Object* pBullet = ObjectFactory<Bullet>::CreateObject(TransInfo.Position, pBridge,2);

    return pBullet;
}