#pragma once
#include "BulletBridge.h"

class NormalBullet : public BulletBridge
{
private:
	Transform p_Pattern[3];

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	NormalBullet();
	virtual ~NormalBullet();
};

