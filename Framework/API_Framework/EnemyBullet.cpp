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

    Speed = 5.0f;
    Damage = 1;

    DrawKey = "EBullet";
}

int EnemyBullet::Update(Transform& _rTransInfo)
{
    _rTransInfo.Position.x -= _rTransInfo.Direction.x * Speed;
    _rTransInfo.Position.y -= _rTransInfo.Direction.y * Speed;

    if (_rTransInfo.Position.x <= 0)
        return 1;

    return 0;
}

void EnemyBullet::Render(HDC _hdc)
{
    Ellipse(_hdc,
        int(RealObject->GetPosition().x - (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y - (RealObject->GetScale().y / 2)),
        int(RealObject->GetPosition().x + (RealObject->GetScale().x / 2)),
        int(RealObject->GetPosition().y + (RealObject->GetScale().y / 2)));
}

void EnemyBullet::Release()
{
}


