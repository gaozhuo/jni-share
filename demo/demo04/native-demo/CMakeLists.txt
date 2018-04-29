cmake_minimum_required(VERSION 3.10)

project(native_demo)

set(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

# 加入jni头文件路径
#include_directories(${JAVA_INCLUDE_PATH})
#include_directories(${JAVA_INCLUDE_PATH2})
# 链接到jvm动态库
link_libraries(${JAVA_JVM_LIBRARY})

add_executable(native_demo main.cpp)