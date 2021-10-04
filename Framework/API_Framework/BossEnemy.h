#pragma once
#include "EnemyBridge.h"

class BossEnemy :public EnemyBridge
{
public:
	//	Bridge* Pattern;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	template <typename T>
	Object* CreateBullet();

public:
	BossEnemy();
	virtual ~BossEnemy();
};