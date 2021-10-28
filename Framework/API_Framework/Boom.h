#pragma once
#include "BulletBridge.h"

class Boom :public BulletBridge
{
private:
	int Frame[2];
	ULONGLONG Time;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	Boom();
	virtual ~Boom();
};

