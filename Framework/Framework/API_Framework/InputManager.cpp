#include "InputManager.h"

InputManager* InputManager::Instance = nullptr;


void InputManager::CheckKey()
{
	Key = 0;

	if (GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W'))
		Key |= KEY_UP;

	if (GetAsyncKeyState(VK_DOWN) || GetAsyncKeyState('S'))
		Key |= KEY_DOWN;

	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
		Key |= KEY_LEFT;

	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
		Key |= KEY_RIGHT;

	if (GetAsyncKeyState(VK_ESCAPE))
		Key |= KEY_ESCAPE;

	if (GetAsyncKeyState(VK_SPACE))
		Key |= KEY_SPACE;

	if (GetAsyncKeyState(VK_RETURN))
		Key |= KEY_ENTER;
}
