#include "EnemyBullet.h"

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
    _rTransInfo.Position.x += _rTransInfo.Direction.x * Speed;
    _rTransInfo.Position.y += _rTransInfo.Direction.y * Speed;

    if (_rTransInfo.Position.x >= (WindowsWidth - 100))
        return 1;

    return 0;
}

void EnemyBullet::Render(HDC _hdc)
{
}

void EnemyBullet::Release()
{
}


