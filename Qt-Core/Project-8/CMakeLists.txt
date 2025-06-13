cmake_minimum_required(VERSION 3.10)
project(MinimalPopplerViewer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

# Manually locate Poppler Qt5 headers and library
find_path(POPPLER_QT5_INCLUDE_DIR poppler-qt5.h PATH_SUFFIXES poppler/qt5)
find_library(POPPLER_QT5_LIBRARY NAMES poppler-qt5)

if (NOT POPPLER_QT5_INCLUDE_DIR OR NOT POPPLER_QT5_LIBRARY)
    message(FATAL_ERROR "Poppler-Qt5 not found. Please install libpoppler-qt5-dev.")
endif()

add_executable(${PROJECT_NAME}
    main.cpp
    pdfitem.cpp
    pdfitem.h
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/qml $<TARGET_FILE_DIR:${PROJECT_NAME}>/qml)


target_include_directories(${PROJECT_NAME} PRIVATE ${POPPLER_QT5_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Qml
    Qt5::Quick
    Qt5::QuickControls2
    ${POPPLER_QT5_LIBRARY}
)
