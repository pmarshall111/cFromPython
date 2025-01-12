cmake_minimum_required(VERSION 3.28)

project(callCFromPython VERSION 1.0 DESCRIPTION "Some dummy funcs for practice")

# Executable
add_executable(cApi.tsk api.cpp)
target_include_directories(cApi.tsk PRIVATE .)
target_compile_options(cApi.tsk PRIVATE -ggdb)

# Lib
add_library(cApiLib SHARED api.cpp)
set_target_properties(cApiLib PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(cApiLib PROPERTIES PUBLIC_HEADER api.h)
target_include_directories(cApiLib PRIVATE .)
