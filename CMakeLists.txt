project(alterlinux-i3-manager)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCES main.cpp mainwindow.cpp)
set(HEADERS mainwindow.h)
set(UI mainwindow.ui)

add_executable(model_view_playground ${SOURCES} ${HEADERS} ${UI})
target_link_libraries(model_view_playground Qt5::Widgets)