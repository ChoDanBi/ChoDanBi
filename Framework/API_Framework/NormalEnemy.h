#pragma once
#include "EnemyBridge.h"

class NormalEnemy :public EnemyBridge
{
public:
	//	Bridge* Pattern;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;


public:
	NormalEnemy();
	virtual ~NormalEnemy();
};
