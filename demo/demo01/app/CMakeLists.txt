# 指定cmake版本
cmake_minimum_required(VERSION 3.4.1)

# so库名称   so库类型   native源代码路径
add_library(native-lib  SHARED  src/main/cpp/native-lib.cpp )

# 查找log库，并将其赋给log-lib变量
find_library(log-lib  log )

# 将log库链接到native-lib中
target_link_libraries(native-lib   ${log-lib} )