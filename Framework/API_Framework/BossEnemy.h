#pragma once
#include "EnemyBridge.h"

class BossEnemy :public EnemyBridge
{
public:
	SKILL Skill;
	MOVE Move;
	float Tick;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	void CreateBullet();
	void MoveAnimation(MOVE _Move);
	void Pattern(SKILL _Skill);

	template <typename T>
	Object* CreateBullet(int _Pattern);

public:
	BossEnemy();
	virtual ~BossEnemy();
};