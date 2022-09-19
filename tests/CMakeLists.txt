find_package(Catch2 3 REQUIRED)
add_executable(tests
               test.cpp
               test_key_values.cpp
               test_counts.cpp
               test_writer.cpp
               test_parser.cpp
              )
target_link_libraries(tests PRIVATE Rhythm Catch2::Catch2WithMain)
