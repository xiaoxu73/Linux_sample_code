# 把目录下所有 .cpp 编成一个可执行文件
include_directories(./include)
file(GLOB SRCS ./src/*.cpp)
add_executable(code4.25 test.cpp ${SRCS})