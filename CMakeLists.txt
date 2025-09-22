cmake_minimum_required(VERSION 3.22)
project(Linux_sample_code)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_C_COMPILER   "/usr/bin/gcc.exe")
# set(CMAKE_CXX_COMPILER "/usr/bin/g++.exe")

# 让 CMake 自动下载/编译 GTest（无需手动装）
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2)   # 写此文时最新 release
FetchContent_MakeAvailable(googletest)

# 设置可执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 递归添加所有含有 CMakeLists.txt 的子目录
file(GLOB_RECURSE SUB_CMAKES CONFIGURE_DEPENDS
     ${CMAKE_SOURCE_DIR}/code/**/CMakeLists.txt)
foreach(_cm ${SUB_CMAKES})
    get_filename_component(_dir ${_cm} DIRECTORY)
    add_subdirectory(${_dir})
endforeach()

# 链接 GTest
# target_link_libraries(test_math gtest_main)   # gtest_main 自带 main()
# include(GoogleTest)
# gtest_discover_tests(test_math)               # 自动把 TEST 注册到 VSCode
