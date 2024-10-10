#include <windows.h>
#include "menu.h"

// Уникальные идентификаторы для элементов меню
enum MenuIdentifiers {
    ID_NEW_INSTANCE = 1,
    ID_OPEN,
    ID_LOAD_RELOAD_INPUT,
    ID_LOAD_ADDITIONAL_BINARY,
    ID_LOAD_IDS_IDT,
    ID_LOAD_PDB,
    ID_LOAD_DBG,
    ID_LOAD_TDS,
    ID_LOAD_FLIRT,
    ID_LOAD_PARSE_C_HEADER,
    ID_PRODUCE_CREATE_MAP,
    ID_PRODUCE_CREATE_ASM,
    ID_PRODUCE_CREATE_INC,
    ID_PRODUCE_CREATE_LST,
    ID_PRODUCE_CREATE_EXE,
    ID_PRODUCE_CREATE_DIF,
    ID_PRODUCE_CREATE_HTML,
    ID_PRODUCE_CREATE_FLOW_GDL,
    ID_PRODUCE_CREATE_CALL_GDL,
    ID_PRODUCE_CREATE_C_HEADER,
    ID_PRODUCE_DUMP_DB_IDC,
    ID_PRODUCE_DUMP_TYPEINFO_IDC,
    ID_SCRIPT_FILE,
    ID_SCRIPT_COMMAND,
    ID_SAVE,
    ID_SAVE_AS,
    ID_TAKE_DB_SNAPSHOT,
    ID_CLOSE,
    ID_QUICK_START,
    ID_EXIT,
    ID_EDIT_COPY,
    ID_EDIT_BEGIN_SELECTION,
    ID_EDIT_SELECT_ALL,
    ID_EDIT_SELECT_IDENTIFIER,
    ID_EDIT_UNDO,
    ID_EDIT_REDO,
    ID_EDIT_EXPORT_DATA,
    ID_EDIT_CODE,
    ID_EDIT_DATA,
    ID_EDIT_STRUCT_VAR,
    ID_EDIT_STRINGS,
    ID_EDIT_ARRAY,
    ID_EDIT_UNDEFINE,
    ID_EDIT_RENAME,
    ID_EDIT_OPERAND_TYPE,
    ID_EDIT_COMMENTS,
    ID_EDIT_SEGMENTS,
    ID_EDIT_STRUCTS,
    ID_EDIT_FUNCTIONS,
    ID_EDIT_PATCH_PROGRAM,
    ID_EDIT_OTHER,
    ID_EDIT_PLUGINS,
    ID_JUMP,
    ID_SEARCH,
    ID_VIEW,
    ID_DEBUGGER,
    ID_OPTIONS,
    ID_WINDOWS,
    ID_HELP
};

// Функция для создания подменю "Load file"
HMENU CreateLoadFileMenu() {
    HMENU hSubMenuLoad = CreateMenu();
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_RELOAD_INPUT, TEXT("Reload the input file"));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_ADDITIONAL_BINARY, TEXT("Additional binary file..."));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_IDS_IDT, TEXT("IDS/IDT file..."));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_PDB, TEXT("PDB file..."));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_DBG, TEXT("DBG file..."));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_TDS, TEXT("TDS file..."));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_FLIRT, TEXT("FLIRT signature file..."));
    AppendMenu(hSubMenuLoad, MF_STRING, ID_LOAD_PARSE_C_HEADER, TEXT("Parse C header file..."));
    return hSubMenuLoad;
}

// Функция для создания подменю "Produce file"
HMENU CreateProduceFileMenu() {
    HMENU hSubProduceFile = CreateMenu();
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_MAP, TEXT("Create MAP file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_ASM, TEXT("Create ASM file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_INC, TEXT("Create INC file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_LST, TEXT("Create LST file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_EXE, TEXT("Create EXE file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_DIF, TEXT("Create DIF file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_HTML, TEXT("Create HTML file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_FLOW_GDL, TEXT("Create flow chart GDL..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_CALL_GDL, TEXT("Create call chart GDL..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_CREATE_C_HEADER, TEXT("Create C header file..."));
    AppendMenu(hSubProduceFile, MF_SEPARATOR, 0, nullptr);
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_DUMP_DB_IDC, TEXT("Dump database to IDC file..."));
    AppendMenu(hSubProduceFile, MF_STRING, ID_PRODUCE_DUMP_TYPEINFO_IDC, TEXT("Dump typeinfo to IDC file..."));
    return hSubProduceFile;
}

// Функция для создания меню "Edit"
HMENU CreateEditMenu() {
    HMENU hMenuEdit = CreateMenu();
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_COPY, TEXT("Copy"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_BEGIN_SELECTION, TEXT("Begin selection"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_SELECT_ALL, TEXT("Select all"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_SELECT_IDENTIFIER, TEXT("Select identifier"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_UNDO, TEXT("Undo"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_REDO, TEXT("Redo"));
    AppendMenu(hMenuEdit, MF_SEPARATOR, 0, nullptr);
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_EXPORT_DATA, TEXT("Export data"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_CODE, TEXT("Code"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_DATA, TEXT("Data"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_STRUCT_VAR, TEXT("Struct var..."));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_STRINGS, TEXT("Strings"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_ARRAY, TEXT("Array"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_UNDEFINE, TEXT("Undefine"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_RENAME, TEXT("Rename"));
    AppendMenu(hMenuEdit, MF_SEPARATOR, 0, nullptr);
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_OPERAND_TYPE, TEXT("Operand type"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_COMMENTS, TEXT("Comments"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_SEGMENTS, TEXT("Segments"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_STRUCTS, TEXT("Structs"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_FUNCTIONS, TEXT("Functions"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_PATCH_PROGRAM, TEXT("Patch program"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_OTHER, TEXT("Other"));
    AppendMenu(hMenuEdit, MF_STRING, ID_EDIT_PLUGINS, TEXT("Plugins"));
    return hMenuEdit;
}

// Функция для создания всей строки меню
HMENU CreateMenuBar() {
    HMENU hMenuBar = CreateMenu();

    // Создание меню File
    HMENU hMenuFile = CreateMenu();
    AppendMenu(hMenuFile, MF_STRING, ID_NEW_INSTANCE, TEXT("New instance"));
    AppendMenu(hMenuFile, MF_STRING, ID_OPEN, TEXT("Open"));
    AppendMenu(hMenuFile, MF_POPUP, (UINT_PTR)CreateLoadFileMenu(), TEXT("Load file"));
    AppendMenu(hMenuFile, MF_POPUP, (UINT_PTR)CreateProduceFileMenu(), TEXT("Produce file"));
    AppendMenu(hMenuFile, MF_STRING, ID_SCRIPT_FILE, TEXT("Script file...\tAlt+F7"));
    AppendMenu(hMenuFile, MF_STRING, ID_SCRIPT_COMMAND, TEXT("Script command...\tShift+F2"));
    AppendMenu(hMenuFile, MF_STRING, ID_SAVE, TEXT("Save\tCtrl+W"));
    AppendMenu(hMenuFile, MF_STRING, ID_SAVE_AS, TEXT("Save as..."));
    AppendMenu(hMenuFile, MF_STRING, ID_TAKE_DB_SNAPSHOT, TEXT("Take database snapshot...\tCtrl+Shift+W"));
    AppendMenu(hMenuFile, MF_STRING, ID_CLOSE, TEXT("Close"));
    AppendMenu(hMenuFile, MF_SEPARATOR, 0, nullptr);
    AppendMenu(hMenuFile, MF_STRING, ID_QUICK_START, TEXT("Quick start"));
    AppendMenu(hMenuFile, MF_SEPARATOR, 0, nullptr);
    AppendMenu(hMenuFile, MF_STRING, ID_EXIT, TEXT("Exit\tAlt+X"));
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)hMenuFile, TEXT("File"));

    // Создание меню Edit
    AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)CreateEditMenu(), TEXT("Edit"));

    // Создание остальных пунктов меню
    AppendMenu(hMenuBar, MF_STRING, ID_JUMP, TEXT("Jump"));
    AppendMenu(hMenuBar, MF_STRING, ID_SEARCH, TEXT("Search"));
    AppendMenu(hMenuBar, MF_STRING, ID_VIEW, TEXT("View"));
    AppendMenu(hMenuBar, MF_STRING, ID_DEBUGGER, TEXT("Debugger"));
    AppendMenu(hMenuBar, MF_STRING, ID_OPTIONS, TEXT("Options"));
    AppendMenu(hMenuBar, MF_STRING, ID_WINDOWS, TEXT("Windows"));
    AppendMenu(hMenuBar, MF_STRING, ID_HELP, TEXT("Help"));

    return hMenuBar;
}
