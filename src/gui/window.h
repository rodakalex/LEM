#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>

// Прототипы функций
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
void RegisterWindowClass(HINSTANCE hInstance);
HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow);
void ShowMainWindow(HWND hwnd, int nCmdShow);

#endif // WINDOW_H
