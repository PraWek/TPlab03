cmake_minimum_required(VERSION 3.10)

project(hello_world)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world PRIVATE
  formatter_lib
  formatter_ex_lib
)

target_include_directories(hello_world PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ../formatter_lib
  ../formatter_ex_lib
)
