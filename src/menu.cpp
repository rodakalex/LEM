#include <windows.h>
#include "menu.h"

// Функция для создания меню
HMENU CreateMenuBar() {
    HMENU hMenuBar = CreateMenu();

    // Создание меню File
    HMENU hMenuFile = CreateMenu();
    AppendMenu(hMenuFile, MF_STRING, 1, TEXT("Open"));
    AppendMenu(hMenuFile, MF_STRING, 2, TEXT("Save"));
    AppendMenu(hMenuFile, MF_STRING, 3, TEXT("Exit"));
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hMenuFile, TEXT("File"));

    // Создание меню Edit
    HMENU hMenuEdit = CreateMenu();
    AppendMenu(hMenuEdit, MF_STRING, 4, TEXT("Undo"));
    AppendMenu(hMenuEdit, MF_STRING, 5, TEXT("Redo"));
    AppendMenu(hMenuEdit, MF_STRING, 6, TEXT("Cut"));
    AppendMenu(hMenuEdit, MF_STRING, 7, TEXT("Copy"));
    AppendMenu(hMenuEdit, MF_STRING, 8, TEXT("Paste"));
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hMenuEdit, TEXT("Edit"));

    // Создание остальных пунктов меню
    AppendMenu(hMenuBar, MF_STRING, 9, TEXT("Jump"));
    AppendMenu(hMenuBar, MF_STRING, 10, TEXT("Search"));
    AppendMenu(hMenuBar, MF_STRING, 11, TEXT("View"));
    AppendMenu(hMenuBar, MF_STRING, 12, TEXT("Debugger"));
    AppendMenu(hMenuBar, MF_STRING, 13, TEXT("Options"));
    AppendMenu(hMenuBar, MF_STRING, 14, TEXT("Windows"));
    AppendMenu(hMenuBar, MF_STRING, 15, TEXT("Help"));

    return hMenuBar;
}
