#pragma once
#include "Headers.h"

class MainUpdate
{
private:
	HDC		m_hdc;
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

