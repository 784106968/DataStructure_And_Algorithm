# cmake 的最小版本要求
cmake_minimum_required(VERSION 3.12)
# 这个CMakeLists管理的工程名称
project(Data_Structure)
set(CMAKE_CXX_STANDARD 14)
#生成可执行程序 语法:add_executable(可执行程序名 要编译的cpp)
add_executable(Stack Stack/Stack.cpp)
add_executable(DFS Algorithm/DFS.cpp)
add_executable(ShStack Stack/ShStack.cpp)
add_executable(LiStack Stack/LiStack.cpp)
add_executable(LinkList LinkList/LinkList.cpp)
add_executable(SqQueue Queue/SqQueue.cpp)