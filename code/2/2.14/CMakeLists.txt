# 把目录下所有 .cpp 编成一个可执行文件
file(GLOB SRCS *.cpp)
add_executable(code2.14 ${SRCS})