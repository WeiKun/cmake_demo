# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)
# 项目信息
project (Demo2.5)

include_directories(math)
aux_source_directory(math MATH_DIR)

# 指定生成目标
add_executable(Demo main.cc ${MATH_DIR})

