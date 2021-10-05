#pragma once
#include "SceneBridge.h"

class Stage4 :public SceneBridge
{
public:
	virtual void Initialize()override;
	virtual void Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

public:
	template <typename T>
	Object* CreateEnemy(Vector3 _Pos);

public:
	Stage4();
	virtual ~Stage4();
};

