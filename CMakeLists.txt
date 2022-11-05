cmake_minimum_required(VERSION 3.21)
project(Labor5OOP)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor5OOP application.cpp Domain.h Domain.cpp InMemoRepository.h InMemoRepository.cpp Controller.cpp Controller.h UI.h UI.cpp test.cppT CSVRepository.h CSVRepository.cpp)
