#pragma once
#include "Object.h"

class StageButton:public Object
{
private:
	bool clear[5];
	int click;
	Transform ButtonPos[5];

public:
	virtual void Initialize()override;
	virtual int Update()override;
	virtual void Render(HDC _hdc)override;
	virtual void Release()override;

	virtual Object* Clone()override { return new StageButton(*this); }

public:
	void StageClear(int _Clear);

public:
	StageButton();
	StageButton(const Transform& _rTransInfo): Object(_rTransInfo) {}
	virtual ~StageButton();
};

