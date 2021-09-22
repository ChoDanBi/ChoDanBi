#pragma once
#include "Scene.h"


class Object;
class Stage : public Scene
{
private:
	Object* State_Back;
	Object* m_pPlayer;
	vector<Object*>* EnemyList;
	vector<Object*>* EnemyBullet;
	vector<Object*>* BulletList;

	vector<Object*>* ObjectList;

	map<string, Bitmap*> ImageList;

	// ** 타일 생성 개수
	int TileWidthCnt;
	int TileHeightCnt;
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;
public:
	Stage();
	virtual ~Stage();
};