#include "Headers.h"
#include "MainUpdate.h"

int main(void)
{
	MainUpdate Main;
	Main.Initialize();
	
	ULONGLONG Time = GetTickCount64(); // 1/1000 초를 반환 하는 함수

	while (true)
	{
		if (Time + 80 < GetTickCount64())
		{
			system("cls");
			Time = GetTickCount64();

			//** 루프
			Main.Update();
			Main.Render();
		}
	}

	return 0;
}
