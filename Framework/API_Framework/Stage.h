#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	int PlayerHitPoint;

	Object* State_Back;
	Object* m_pPlayer;
	vector<Object*>* BulletList;

	vector<Object*>* EnemyList;
	vector<Object*>* EBulletList;
	

	map<string, Bitmap*> ImageList;

public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	template <typename T>
	Object* CreateBullet(Vector3 _Pos);


public:
	Stage();
	virtual ~Stage();
};