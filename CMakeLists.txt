cmake_minimum_required(VERSION 3.9.2)
project(graph)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
include_directories(deps/sparsematrix/include)
include_directories(deps/sparsematrix/deps/avltree/include)

add_subdirectory(deps/sparsematrix)
#add_subdirectory(deps/googletest)

# include_directories(deps/sparsematrix/include)
# include_directories(deps/sparsematrix/deps/avltree/include)

add_executable(graph main.cpp) 

# enable_testing()

# file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

# foreach(_test_file ${TEST_SRC_FILES})
#   get_filename_component(_test_name ${_test_file} NAME_WE)
#   add_executable(${_test_name} ${_test_file})
#   target_link_libraries(${_test_name} gtest gtest_main)
#   add_test(NAME ${_test_name} COMMAND ${_test_name})
# endforeach()