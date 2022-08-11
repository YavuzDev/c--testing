cmake_minimum_required(VERSION 3.16)
project(kiraged_unit_testing)

set(CMAKE_CXX_STANDARD 20)

add_executable(kiraged_unit_testing main.cpp test/TestManager.cpp test/TestManager.h test/Assert.h test/Group.cpp test/Group.h test/TestResult.cpp test/TestResult.h)