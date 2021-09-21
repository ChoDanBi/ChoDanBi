#pragma once
#include "EnemyBridge.h"

class Enemy1:public EnemyBridge
{
public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Enemy1();
	virtual ~Enemy1();
};

