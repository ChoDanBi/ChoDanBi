#pragma once
#include "Headers.h"

class Object;
class Scene
{
protected:
	int PlayerHitPoint;
	ULONGLONG PlayTime;
	ULONGLONG Timer;

	Object* SelectButton;
	Object* State_Back;
	Object* m_pPlayer;
	vector<Object*>* BulletList;

	vector<Object*>* EnemyList;
	vector<Object*>* EBulletList;


	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;
public:
	Scene();
	virtual ~Scene();
};
