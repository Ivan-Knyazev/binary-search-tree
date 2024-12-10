set(CMAKE_CXX_STANDARD 20)

add_executable(test_heaptree test_heaptree.cpp)
target_link_libraries(test_heaptree heaptree)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT test_heaptree)
