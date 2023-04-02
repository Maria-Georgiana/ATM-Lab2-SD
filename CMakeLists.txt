cmake_minimum_required(VERSION 3.24)
project(ATM_Lab2_SD)

set(CMAKE_CXX_STANDARD 17)

add_executable(ATM_Lab2_SD main.cpp Collection.h Collection.cpp Iterator.cpp Tranzactie.h Tranzactie.cpp ATM.h ATM.cpp)
