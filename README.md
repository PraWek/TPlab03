## Лабораторная работа 3: Сборка проекта с помощью CMake

formater_ex_lib - Расширенная библиотека  
./formater_ex_lib/CmakeLists.txt
```
cat > formatter_ex_lib/CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.5)
project(formatter_ex LANGUAGES CXX)

if(NOT TARGET formatter)
    add_subdirectory(${CMAKE_SOURCE_DIR}/formatter_lib ${CMAKE_CURRENT_BINARY_DIR}/formatter_lib)
endif()

if(NOT TARGET formatter_ex)
    add_library(formatter_ex STATIC formatter_ex.cpp)
    target_include_directories(formatter_ex PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
    target_link_libraries(formatter_ex PUBLIC formatter)
endif()
EOF
```
formater_lib - Библиотека formatter  
./formater_lib/CmakeLists.txt
```
cat > formatter_lib/CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.5)

project(formatter LANGUAGES CXX VERSION 1.0)

if(NOT TARGET formatter)
    add_library(formatter STATIC formatter.cpp)
    target_include_directories(formatter PUBLIC 
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    )
endif()
EOF
```

hello_world_application - Пример приложения  
./hello_world_application/CmakeLists.txt
```
cat > hello_world_application/CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.5)

project(hello_world LANGUAGES CXX)

if(NOT TARGET formatter_ex)
    add_subdirectory(${CMAKE_SOURCE_DIR}/formatter_ex_lib 
                   ${CMAKE_CURRENT_BINARY_DIR}/formatter_ex_lib)
endif()

add_executable(hello_world hello_world.cpp)
target_link_libraries(hello_world PRIVATE formatter_ex)
EOF
```

solver_application - Приложение, решающее задания  
./solver_application/CmakeLists.txt
```
cat > solver_application/CMakeLists.txt <<EOF
cmake_minimum_required(VERSION 3.5)
project(solver_app LANGUAGES CXX)

if(NOT TARGET formatter_ex)
    add_subdirectory(${CMAKE_SOURCE_DIR}/formatter_ex_lib 
                   ${CMAKE_CURRENT_BINARY_DIR}/formatter_ex_lib)
endif()

if(NOT TARGET solver_library)
    add_subdirectory(${CMAKE_SOURCE_DIR}/solver_lib 
                   ${CMAKE_CURRENT_BINARY_DIR}/solver_library)
endif()

add_executable(solver equation.cpp)
target_link_libraries(solver PRIVATE formatter_ex solver_lib)
EOF
```

solver_library - Библиотека для решения уравнений  
./solver_library/CmakeLists.txt
```
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
```

Локальный CmakeLists.txt  
./CmakeLists.txt
```
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
```

Создание директории для сборки и генерация Makefile (из корня проекта)
```
mkdir build && cd build
cmake ..
```

-- Configuring done (0.0s)  
-- Generating done (0.0s)  
-- Build files have been written to: /home/Lev/Документы/TPlab03/build  

Сборка всех компонентов
```
cmake --build .
```

[ 20%] Built target formatter  
[ 40%] Built target formatter_ex  
[ 60%] Built target solver_library  
[ 80%] Built target hello_world  
[100%] Built target solver  

Пример для (x^2 + 4x + 3)
```
└─▪ ./hello_world_application/hello_world 
-------------------------
hello, world!
-------------------------
└─▪ ./solver_application/solver 
1 4 3
-------------------------
x1 = -3.000000
-------------------------
-------------------------
x2 = -1.000000
-------------------------
```
