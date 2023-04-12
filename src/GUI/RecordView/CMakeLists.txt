add_library(libRecordView
    recordview.cpp recordview.h
    abstract_single_item_view.h abstractsingleitemview.cpp
)

target_link_libraries(libRecordView PRIVATE libdatabasemodel Qt6::Widgets)
target_include_directories(libRecordView PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
