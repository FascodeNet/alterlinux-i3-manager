cmake_minimum_required(VERSION 3.5)

project(alterlinux-i3-manager LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories("inc")

add_executable(alterlinux-i3-manager
  src/main.cpp
  src/mainwindow.cpp
)

target_link_libraries(alterlinux-i3-manager PRIVATE Qt5::Widgets)
