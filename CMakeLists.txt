cmake_minimum_required(VERSION 3.5)

project(DatabaseQTApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS
        Core
        Widgets
        Gui
        REQUIRED)


add_subdirectory(src)
