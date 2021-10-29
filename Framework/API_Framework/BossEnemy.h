#pragma once
#include "EnemyBridge.h"

class BossEnemy :public EnemyBridge
{
public:
	Bitmap* Image;
	SKILL Skill;
	MOVE Move;
	float Tick;
	bool Moveing;
	bool Event;
	int NumSkill;

public:
	virtual void Initialize()override;
	virtual int Update(Transform& _rTransInfo)override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	void CreateBullet(Transform& _rTransInfo);
	void MoveAnimation(MOVE _Move, Transform& _rTransInfo);
	void Pattern(SKILL _Skill, Transform& _rTransInfo);

	template <typename T>
	Object* CreateBullet(int _Pattern, Transform& _rTransInfo);

public:
	BossEnemy();
	virtual ~BossEnemy();
};