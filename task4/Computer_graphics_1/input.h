#pragma once



#pragma comment(lib, "dxguid.lib")
#include <directxmath.h>
#include <windows.h>

using namespace DirectX;

class Input {
public:
	int lastMouseX = 0;
	int lastMouseY = 0;
	Input(HINSTANCE hinst, HWND hwnd, int screenW, int screenH);
	int m_screenW = 0, m_screenH = 0;
	BYTE keyState[256];
	void resize(int screenW, int screenH);
	bool IsLeftPressed();
	bool IsRightPressed();
	bool IsUpPressed();
	bool IsDownPressed();
	int GetZoom();
	XMFLOAT3 GetMouseMove();

private:
	bool IsMouseButtonPressed();

};