#include <windows.h>
#include "window.h"
#include "menu.h"

const TCHAR g_className[] = TEXT("myWindowClass");

// Обработчик сообщений окна
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
        }
        break;
        case WM_COMMAND: // Обработка нажатий на пункты меню
            switch (LOWORD(wParam)) {
                case 3: // Exit
                    DestroyWindow(hwnd);
                    break;
                // Добавьте обработку других пунктов меню здесь
            }
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// Функция для регистрации класса окна
void RegisterWindowClass(HINSTANCE hInstance) {
    WNDCLASSEX wc;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_className;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
        exit(0); // Завершаем программу, если регистрация класса не удалась
    }
}

// Функция для создания основного окна
HWND CreateMainWindow(HINSTANCE hInstance, int nCmdShow) {
    RECT workArea;
    SystemParametersInfo(SPI_GETWORKAREA, 0, &workArea, 0);

    HWND hwnd = CreateWindowEx(
        0, // Убрали WS_EX_CLIENTEDGE для устранения рамок
        g_className,
        TEXT("LEM"),
        WS_OVERLAPPEDWINDOW, // Окно с рамками и кнопками управления
        workArea.left, workArea.top, // Левый верхний угол рабочей области
        workArea.right - workArea.left, // Ширина окна (вся рабочая область)
        workArea.bottom - workArea.top, // Высота окна (вся рабочая область)
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, TEXT("Window Creation Failed!"), TEXT("Error!"), MB_ICONEXCLAMATION | MB_OK);
        exit(0); // Завершаем программу, если создание окна не удалось
    }

    // Создание и установка меню
    HMENU hMenu = CreateMenuBar();
    SetMenu(hwnd, hMenu);

    ShowMainWindow(hwnd, nCmdShow);
    return hwnd;
}

// Функция для отображения основного окна
void ShowMainWindow(HWND hwnd, int nCmdShow) {
    ShowWindow(hwnd, SW_SHOWMAXIMIZED);
    UpdateWindow(hwnd);
}
