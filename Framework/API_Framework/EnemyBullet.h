#pragma once
#include "BulletBridge.h"
class EnemyBullet:public BulletBridge
{
private:
	Transform e_Pattern[5];

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	EnemyBullet();
	virtual ~EnemyBullet();
};

