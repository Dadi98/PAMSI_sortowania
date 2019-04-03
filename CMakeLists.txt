cmake_minimum_required(VERSION 3.13)
project(untitled2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} "-static")
add_executable(untitled2 main.cpp QS.h QS.cpp tab.cpp tab.h Scalanie.h Scalanie.cpp kopiec.h kopiec.cpp )