#pragma once
#include "Bridge.h"

class EnemyBridge:public Bridge
{
protected:
	float Speed;
	int EnemyHp;
public:
	int SetHp() { return EnemyHp; }
public:
	virtual void Initialize()PURE;
	virtual int Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	EnemyBridge();
	virtual ~EnemyBridge();
};