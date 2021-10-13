#pragma once
#include "EnemyBridge.h"

class EliteEnemy :public EnemyBridge
{
public:
	//	Bridge* Pattern;
	ULONGLONG MTime;
	int Move;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	template <typename T>
	Object* CreateBullet(int _Pattern);

public:
	EliteEnemy();
	virtual ~EliteEnemy();
};