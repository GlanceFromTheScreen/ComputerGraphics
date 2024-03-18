#include "input.h"

Input::Input(HINSTANCE hinst, HWND hwnd, int screenW, int screenH) {
    m_screenW = screenW;
    m_screenH = screenH;
}

bool Input::IsLeftPressed() {
    if (!GetKeyboardState(keyState))
        return false;
    return keyState[VK_LEFT] & 0x80 || keyState['A'] & 0x80;
}

bool Input::IsRightPressed() {

    if (!GetKeyboardState(keyState))
        return false;
    return keyState[VK_RIGHT] & 0x80 || keyState['D'] & 0x80;
}

bool Input::IsUpPressed() {
    if (!GetKeyboardState(keyState))
        return false;
    return keyState[VK_UP] & 0x80 || keyState['W'] & 0x80;
}

bool Input::IsDownPressed() {
    if (!GetKeyboardState(keyState))
        return false;
    return keyState[VK_DOWN] & 0x80 || keyState['S'] & 0x80;
}


int Input::GetZoom() {
    if (GetKeyboardState(keyState)) {
        if (keyState[VK_OEM_MINUS] & 0x80) {
            return -1;
        }
        if (keyState[VK_OEM_PLUS] & 0x80) {
            return 1;
        }
    }
    return 0;
}

bool Input::IsMouseButtonPressed() {
    if (GetKeyboardState(keyState) && (keyState[VK_LBUTTON] & 0x80 || keyState[VK_RBUTTON] & 0x80))
    {

        return true;
    }
    else
        return false;
}

XMFLOAT3 Input::GetMouseMove() {
    if (IsMouseButtonPressed()) {
        POINT cursorPos;
        GetCursorPos(&cursorPos);


        float deltaX = static_cast<float>(cursorPos.x - lastMouseX);
        float deltaY = static_cast<float>(cursorPos.y - lastMouseY);

        lastMouseX = cursorPos.x;
        lastMouseY = cursorPos.y;

        return DirectX::XMFLOAT3(deltaX, deltaY, 0.0f);
    }
    else {
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        lastMouseX = cursorPos.x;
        lastMouseY = cursorPos.y;
        return DirectX::XMFLOAT3(0.0f, 0.0f, 0.0f);
    }

}

void Input::resize(int screenW, int screenH) {
    m_screenH = screenH;
    m_screenW = screenW;
}
