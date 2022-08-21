add_library(Rhythm note.cpp rhythm.cpp)

target_include_directories(Rhythm
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )
