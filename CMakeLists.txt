cmake_minimum_required(VERSION 3.10)
project(NoIDA)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Указываем директории для include
include_directories(
    include
    ${CMAKE_SOURCE_DIR}/third_party/capstone/include
    ${CMAKE_SOURCE_DIR}/third_party/keystone/include
    ${CMAKE_SOURCE_DIR}/third_party/zydis/include
)

# Собираем все исходные файлы в переменную SOURCES
file(GLOB_RECURSE SOURCES
    src/*.cpp
    src/*.c
)

# Добавляем флаг WIN32 для указания, что это GUI-приложение
add_executable(NoIDA WIN32 ${SOURCES})

# Добавляем необходимые библиотеки Windows
target_link_libraries(NoIDA
    kernel32
    user32
    gdi32
    winspool
    shell32
    ole32
    oleaut32
    uuid
    comdlg32
    advapi32
)
