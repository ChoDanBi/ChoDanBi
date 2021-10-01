#pragma once
#include "Scene.h"

class Object;
class Stage : public Scene
{


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