
set(PROJECT_SOURCES
        main.cpp
)

add_executable(DatabaseQTExec
    ${PROJECT_SOURCES}
)

target_link_libraries(DatabaseQTExec PRIVATE libgui Qt6::Widgets)

