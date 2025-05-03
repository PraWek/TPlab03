cat > solver_library/CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.5)
project(solver_library LANGUAGES CXX)

if(NOT TARGET solver_library)
    add_library(solver_library STATIC solver.cpp)
    target_include_directories(solver_library PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
endif()
EOF
