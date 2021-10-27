#pragma once
#include "Headers.h"

class MainUpdate
{
private:
	HDC		m_hdc;
	Bitmap* Image;
public:
	void Initialize();
	void Update();
	void Render();
	void Release();
public:
	MainUpdate();
	~MainUpdate();
};

// ** »ç¿îµå

