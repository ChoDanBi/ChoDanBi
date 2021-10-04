#pragma once
#include "EnemyBridge.h"

class EliteEnemy :public EnemyBridge
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
	EliteEnemy();
	virtual ~EliteEnemy();
};