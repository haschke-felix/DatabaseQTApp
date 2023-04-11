
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

add_executable(DatabaseQTExec
    ${PROJECT_SOURCES}
)

target_link_libraries(DatabaseQTExec PRIVATE Qt6::Widgets)

