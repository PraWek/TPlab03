cmake_minimum_required(VERSION 3.10)

project(solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(solver equation.cpp)

target_include_directories(solver PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${SOLVER_DIR_INCLUDE}
)

target_link_libraries(solver PRIVATE
  formatter_lib
  formatter_ex_lib
  solver_lib
)
