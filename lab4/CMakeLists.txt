cmake_minimum_required(VERSION 3.12)
project(lab_3)

set(CMAKE_CXX_STANDARD 17)

add_executable(train main.cpp train.h train.cpp datetime.h datetime.cpp)