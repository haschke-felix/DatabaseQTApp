add_library(libgui
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

target_link_libraries(libgui PRIVATE Qt6::Widgets)
target_include_directories(libgui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
