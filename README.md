## Лабораторная работа 3: Сборка проекта с помощью CMake

formater_ex_lib - Расширенная библиотека  
./formater_ex_lib/CmakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(formatter_ex_lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib formatter_lib_dir)
add_library(formatter_ex_lib STATIC ${CMAKE_CURRENT_SOURCE_DIR}/formatter_ex.cpp)
target_include_directories(formatter_ex_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../formatter_lib)
target_link_libraries(formatter_ex_lib formatter_lib)
```
```
cmake -H. -B_build
```
-- The C compiler identification is GNU 13.3.0  
-- The CXX compiler identification is GNU 13.3.0  
-- Detecting C compiler ABI info  
-- Detecting C compiler ABI info - done  
-- Check for working C compiler: /usr/bin/cc - skipped  
-- Detecting C compile features  
-- Detecting C compile features - done  
-- Detecting CXX compiler ABI info  
-- Detecting CXX compiler ABI info - done  
-- Check for working CXX compiler: /usr/bin/c++ - skipped  
-- Detecting CXX compile features  
-- Detecting CXX compile features - done  
-- Configuring done (1.3s)  
-- Generating done (0.0s)  
-- Build files have been written to: /home/Lev/Документы/TPlab03/formatter_ex_lib/_build  
```
cmake --build _build
```
[ 25%] Building CXX object CMakeFiles/formatter_ex_lib.dir/formatter_ex.cpp.o  
[ 50%] Linking CXX static library libformatter_ex_lib.a  
[ 50%] Built target formatter_ex_lib  
[ 75%] Building CXX object formatter_lib_dir/CMakeFiles/formatter.dir/formatter.cpp.o  
[100%] Linking CXX static library libformatter.a  
[100%] Built target formatter  
  
formater_lib - Библиотека formatter  
./formater_lib/CmakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(formatter)
add_library(formatter STATIC formatter.cpp)
target_include_directories(formatter PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
```
```
cmake -H. -B_build
```  
-- The C compiler identification is GNU 13.3.0  
-- The CXX compiler identification is GNU 13.3.0  
-- Detecting C compiler ABI info  
-- Detecting C compiler ABI info - done  
-- Check for working C compiler: /usr/bin/cc - skipped  
-- Detecting C compile features  
-- Detecting C compile features - done  
-- Detecting CXX compiler ABI info  
-- Detecting CXX compiler ABI info - done  
-- Check for working CXX compiler: /usr/bin/c++ - skipped  
-- Detecting CXX compile features  
-- Detecting CXX compile features - done  
-- Configuring done (0.8s)  
-- Generating done (0.0s)  
-- Build files have been written to: /home/Lev/Документы/TPlab03/formatter_lib/_build  
```
cmake --build _build
```
[ 50%] Building CXX object CMakeFiles/formatter.dir/formatter.cpp.o  
[100%] Linking CXX static library libformatter.a  
[100%] Built target formatter  
  
hello_world_application - Пример приложения  
./hello_world_application/CmakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
project(Hello_World)
add_library(formatter_lib STATIC ../formatter_lib/formatter.cpp)
target_include_directories(formatter_lib PUBLIC ../formatter_lib)
add_library(formatter_ex_lib STATIC ../formatter_ex_lib/formatter_ex.cpp)
target_include_directories(formatter_ex_lib PUBLIC ../formatter_ex_lib)
add_executable(hello_world hello_world.cpp)
target_link_libraries(formatter_ex_lib formatter_lib)
target_link_libraries(hello_world formatter_ex_lib)
```
```
cmake -H. -B_build
```
-- The C compiler identification is GNU 13.3.0  
-- The CXX compiler identification is GNU 13.3.0  
-- Detecting C compiler ABI info  
-- Detecting C compiler ABI info - done  
-- Check for working C compiler: /usr/bin/cc - skipped  
-- Detecting C compile features  
-- Detecting C compile features - done  
-- Detecting CXX compiler ABI info  
-- Detecting CXX compiler ABI info - done  
-- Check for working CXX compiler: /usr/bin/c++ - skipped  
-- Detecting CXX compile features  
-- Detecting CXX compile features - done  
-- Configuring done (2.0s)  
-- Generating done (0.0s)  
-- Build files have been written to: /home/Lev/Документы/TPlab03/hello_world_application/_build  
```
cmake --build _build
```
[ 16%] Building CXX object CMakeFiles/formatter_lib.dir/home/Lev/Документы/TPlab03/formatter_lib/formatter.cpp.o  
[ 33%] Linking CXX static library libformatter_lib.a  
[ 33%] Built target formatter_lib  
[ 50%] Building CXX object CMakeFiles/formatter_ex_lib.dir/home/Lev/Документы/TPlab03/formatter_ex_lib/formatter_ex.cpp.o  
[ 66%] Linking CXX static library libformatter_ex_lib.a  
[ 66%] Built target formatter_ex_lib  
[ 83%] Building CXX object CMakeFiles/hello_world.dir/hello_world.cpp.o  
[100%] Linking CXX executable hello_world  
[100%] Built target hello_world  
  
solver_lib - Библиотека для решения уравнений  
./solver_lib/CmakeLists.txt
```
cmake_minimum_required(VERSION 3.10)
project(Solver)
add_library(formatter_lib STATIC ../formatter_lib/formatter.cpp)
target_include_directories(formatter_lib PUBLIC ../formatter_lib)
add_library(solver STATIC ../solver_lib/solver.cpp)
target_include_directories(solver PUBLIC ../solver_lib)
add_library(formatter_ex_lib STATIC ../formatter_ex_lib/formatter_ex.cpp)
target_include_directories(formatter_ex_lib PUBLIC ../formatter_ex_lib)
add_executable(solver_app equation.cpp)
target_link_libraries(formatter_ex_lib formatter_lib)
target_link_libraries(solver_app formatter_ex_lib)
target_link_libraries(solver_app solver)
```
```
cmake -B build
```
-- The C compiler identification is GNU 13.3.0  
-- The CXX compiler identification is GNU 13.3.0  
-- Detecting C compiler ABI info  
-- Detecting C compiler ABI info - done  
-- Check for working C compiler: /usr/bin/cc - skipped  
-- Detecting C compile features  
-- Detecting C compile features - done  
-- Detecting CXX compiler ABI info  
-- Detecting CXX compiler ABI info - done  
-- Check for working CXX compiler: /usr/bin/c++ - skipped  
-- Detecting CXX compile features  
-- Detecting CXX compile features - done  
-- Configuring done (5.0s)  
-- Generating done (0.1s)  
-- Build files have been written to: /home/Lev/Документы/TPlab03/solver_application/build  
```
cmake --build build
```
[ 12%] Building CXX object CMakeFiles/formatter_lib.dir/home/Lev/Документы/TPlab03/formatter_lib/formatter.cpp.o  
[ 25%] Linking CXX static library libformatter_lib.a  
[ 25%] Built target formatter_lib  
[ 37%] Building CXX object CMakeFiles/solver.dir/home/Lev/Документы/TPlab03/solver_lib/solver.cpp.o  
[ 50%] Linking CXX static library libsolver.a  
[ 50%] Built target solver  
[ 62%] Building CXX object CMakeFiles/formatter_ex_lib.dir/home/Lev/Документы/TPlab03/formatter_ex_lib/formatter_ex.cpp.o  
[ 75%] Linking CXX static library libformatter_ex_lib.a  
[ 75%] Built target formatter_ex_lib  
[ 87%] Building CXX object CMakeFiles/solver_app.dir/equation.cpp.o  
[100%] Linking CXX executable solver_app  
[100%] Built target solver_app
