# 把目录下所有 .cpp 编成一个可执行文件
file(GLOB SRCS *.c)
add_executable(code3.1 ${SRCS})