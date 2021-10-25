#pragma once
#include "Headers.h"
#include "SoundManager.h"

class Scene
{
public:
	virtual void Initialize()PURE;
	virtual void Update()PURE;
	virtual void Render(HDC _hdc)PURE;
	virtual void Release()PURE;

public:
	Scene();
	virtual ~Scene();
};
