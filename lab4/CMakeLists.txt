cmake_minimum_required(VERSION 3.12)
project(lab_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(train train.cpp main.cpp datetime.h train.h)