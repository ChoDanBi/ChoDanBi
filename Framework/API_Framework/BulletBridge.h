#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	float Speed;
	float Damage;
public:
	int GetDamage() { return Damage; }

public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	BulletBridge();
	virtual ~BulletBridge();
};

