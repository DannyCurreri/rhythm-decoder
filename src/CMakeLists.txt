add_library(note note.cpp)

target_include_directories(note
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )
