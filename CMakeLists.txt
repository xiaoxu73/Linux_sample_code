cmake_minimum_required(VERSION 3.22)
project(Linux_coding)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_COMPILER "D:\\tools\\msys64\\mingw64\\bin\\gcc.exe")

set(CMAKE_CXX_COMPILER "D:\\tools\\msys64\\mingw64\\bin\\g++.exe")  # 指定编译器路径

# add_compile_options(
#     -finput-charset=utf-8 
#     -fexec-charset=utf-8 
# )

# 添加可执行文件

set(CMAKE_C_STANDARD 99)

add_executable(test code/1/1.1/test.cpp)