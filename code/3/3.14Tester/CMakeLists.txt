# # 把目录下所有 .cpp 编成一个可执行文件
# file(GLOB SRCS *.cpp)
# add_executable(code3.14Tester ${SRCS})

# 测试源码
file(GLOB TEST_SRCS *.cpp)
# 被测 Logger 实现
list(APPEND TEST_SRCS
    ../3.14Tester/CLLogger.cpp
    ../3.14Tester/CLStatus.cpp
)
add_executable(code3.14Tester ${TEST_SRCS})

# 链接 GTest（关键）
target_link_libraries(code3.14Tester
    GTest::gtest      # 头文件 + 库
    GTest::gtest_main # 自带 main()，省得自己写
)

# 注册测试（可选，但建议加）
include(GoogleTest)
gtest_discover_tests(code3.14Tester)