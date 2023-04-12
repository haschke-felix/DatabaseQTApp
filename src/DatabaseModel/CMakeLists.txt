add_library(libdatabasemodel
    databasetablemodel.cpp databasetablemodel.h
    abstractdatabasemodel.cpp abstractdatabasemodel.h
    abstract_index.cpp abstract_index.h
)

target_link_libraries(libdatabasemodel PRIVATE Qt6::Core)
target_include_directories(libdatabasemodel PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
