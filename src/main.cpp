#include <windows.h>
#include "window.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    RegisterWindowClass(hInstance);
    HWND hwnd = CreateMainWindow(hInstance, nCmdShow);
    
    // Цикл сообщений
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
