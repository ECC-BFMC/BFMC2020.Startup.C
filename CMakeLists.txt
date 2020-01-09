# INCLUDE(CMakeForceCompiler)
cmake_minimum_required (VERSION 2.8.11)
project(bosch_adc_lab)

if(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
endif()

find_package(Boost REQUIRED COMPONENTS system thread)
include_directories(include)
file(GLOB SOURCES "src/*.cpp" "src/*/*.cpp")

add_executable(app1 app1.cpp ${SOURCES})

target_link_libraries (app1 ${Boost_LIBRARIES} -lpthread -lm)
