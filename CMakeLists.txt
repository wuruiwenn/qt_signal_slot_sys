
# 指定构建系统所需的 CMake 的最低版本
cmake_minimum_required(VERSION 2.8)

# 项目名
project(wrwSigSlot)

# 向项目添加<头文件，即.h>搜索路径
# 当编译器编译源文件时，它会在这些目录中查找 你.cpp文件中 #include 指令指定的头文件
# ${PROJECT_SOURCE_DIR}/include 是一个变量，代表项目的根目录
include_directories(${PROJECT_SOURCE_DIR}/src)


# CMakeLists.txt 文件不需要显式列出所有的 .cpp 文件路径
# 但需要告诉 CMake 要编译哪些源文件，指定要使用哪些源文件来生成exe，使用add_executable
# add_executable(wrwSigSlot src/MyWidget.cpp src/moc_MyWidget.cpp src/main.cpp)

# 若需指定的 .cpp文件 很多，可以将指定目录下的源文件列表存放到变量中
# 使用aux_source_directory (func SRC_LIST)
# 然后 ${} 取这个变量的值，最后调用 add_executable即可

aux_source_directory(src SRC_LIST)

add_executable(wrwSigSlot ${SRC_LIST})









