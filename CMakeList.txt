cat > CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.5)
project(lab03 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

cmake_policy(SET CMP0002 NEW)
cmake_policy(SET CMP0079 NEW)

add_subdirectory(formatter_lib)
add_subdirectory(formatter_ex_lib)
add_subdirectory(solver_library)
add_subdirectory(hello_world_application)
add_subdirectory(solver_application)
EOF
