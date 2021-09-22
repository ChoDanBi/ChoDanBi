#pragma once
#include "Bridge.h"

class BulletBridge : public Bridge
{
protected:
	float Speed;
	int Damage;
public:
	int GetDamage() { return Damage; }
	void SetDamage(int _Damage) { Damage = _Damage; }
public:
	virtual void Initialize()PURE;
	virtual int Update(Transform& _rTransInfo)PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	BulletBridge();
	virtual ~BulletBridge();
};

