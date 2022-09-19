add_library(Rhythm
            note.cpp
            rhythm.cpp
            rhythm_io_facilities.cpp)

target_include_directories(Rhythm
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )

add_executable(rd
               note.cpp
               main.cpp
               rhythm.cpp
               rhythm_io_facilities.cpp)
