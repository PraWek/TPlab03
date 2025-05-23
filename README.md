## Лабораторная работа 3: Сборка проекта с помощью CMake

formater_ex_lib - Расширенная библиотека  
./formater_ex_lib/CmakeLists.txt  
```
cmake_minimum_required(VERSION 3.10)

project(formatter_ex_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter_ex_lib STATIC formatter_ex.cpp formatter_ex.h)

target_include_directories(formatter_ex_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib
)

target_link_libraries(formatter_ex_lib PUBLIC
  formatter_lib
)
```
  
```
cmake -H. -B_build
```
  
formater_lib - Библиотека formatter  
./formater_lib/CmakeLists.txt  
```
cmake_minimum_required(VERSION 3.10)

project(formatter_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(formatter_lib STATIC formatter.cpp formatter.h)

target_include_directories(formatter_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
```
  
```
cmake -H. -B_build
```
  
hello_world_application - Пример приложения  
./hello_world_application/CmakeLists.txt  
```
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
```
  
```
cmake -H. -B_build
```
  
./solver_application/CmakeLists.txt  
```
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
```
  
```
cmake -B build
```
  
solver_lib - Библиотека для решения уравнений  
./solver_lib/CmakeLists.txt  
```
cmake_minimum_required(VERSION 3.10)

project(solver_lib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(solver_lib STATIC solver.cpp solver.h)

target_include_directories(solver_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}
)
```
  
```
cmake -B build
```

