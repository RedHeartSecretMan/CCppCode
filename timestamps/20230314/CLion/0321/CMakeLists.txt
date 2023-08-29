# 设置 CMake 最低版本要求
cmake_minimum_required(VERSION 3.21)

# 设置项目名字
project(test1)
project(test2)

# 设置 C/CPP 标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)

# 设置输入输出库与基础函数库
include_directories(includes/stdio)
include_directories(includes/stdlib)
include_directories(includes/iostream)
include_directories(include/cstdlib)

# 找到源文件地址
aux_source_directory(1 main1)
aux_source_directory(2 main2)

# 输出源文件地址
message(${main1})
message(${main2})

# 编译输出可执行文件
add_executable(test1 ${main1})
add_executable(test2 ${main2})
