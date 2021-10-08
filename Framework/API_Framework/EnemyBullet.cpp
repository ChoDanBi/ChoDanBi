#include "EnemyBullet.h"
#include "Object.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize()
{
    TransInfo.Scale = Vector3(16.0f,12.0f);
    TransInfo.Position = Vector3(0.0f, 0.0f);

    Speed = 5.0f;
    Damage = 1;

    RealObject->SetDamage(Damage);
    RealObject->SetScale(TransInfo.Scale);
    RealObject->SetColliderScale(TransInfo.Scale);

    DrawKey = "EBullet";
}

int EnemyBullet::Update(Transform& _rTransInfo)
{
    _rTransInfo.Position.x -= _rTransInfo.Direction.x * Speed ;
    _rTransInfo.Position.y -= _rTransInfo.Direction.y * Speed ;

    RealObject->SetColliderPosition(_rTransInfo.Position.x, _rTransInfo.Position.y);

    if (_rTransInfo.Position.x <= 0)
        return 1;



    return 0;
}

void EnemyBullet::Render(HDC _hdc)
{
    TransparentBlt(_hdc, // ** 최종 출력 위치
        int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
        int(RealObject->GetScale().x),
        int(RealObject->GetScale().y),
        ImageList[DrawKey]->GetMemDC(),
        0, 0,
        int(RealObject->GetScale().x),
        int(RealObject->GetScale().y),
        RGB(255, 0, 255));
    /*
    Ellipse(_hdc,
        int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
        int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));*/
}

void EnemyBullet::Release()
{
}


