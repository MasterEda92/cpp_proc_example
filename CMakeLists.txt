cmake_minimum_required(VERSION 3.15)
project(Proc_Example)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proc_Example src/main.cpp src/contacts_stru.h src/helpers.h
                            src/helpers.cpp src/handlers.h src/handlers.cpp)
