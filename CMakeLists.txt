cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

set(TOTAL_C_LABS_COUNT 0)
set(TOTAL_CXX_LABS_COUNT 0)

file(GLOB_RECURSE C_FILES "labs/*.c")
file(GLOB_RECURSE CXX_FILES "labs/*.cpp")

project(CLabs LANGUAGES C)

foreach(C_FILE IN LISTS C_FILES)
    string(REPLACE ".c" "" LAB_TASK_NAME ${C_FILE})
    string(REPLACE "${CMAKE_SOURCE_DIR}/labs/" "" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(REPLACE "/" "_" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(TOUPPER ${LAB_TASK_NAME} LAB_TASK_NAME)
    add_executable(${LAB_TASK_NAME} ${C_FILE})
    math(EXPR TOTAL_C_LABS_COUNT ${TOTAL_C_LABS_COUNT}+1)
endforeach()

project(CXXLabs LANGUAGES CXX)

foreach(CXX_FILE IN LISTS CXX_FILES)
    string(REPLACE ".cpp" "" LAB_TASK_NAME ${CXX_FILE})
    string(REPLACE "${CMAKE_SOURCE_DIR}/labs/" "" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(REPLACE "/" "_" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(TOUPPER ${LAB_TASK_NAME} LAB_TASK_NAME)
    add_executable(${LAB_TASK_NAME} ${CXX_FILE})
    math(EXPR TOTAL_CXX_LABS_COUNT ${TOTAL_CXX_LABS_COUNT}+1)
endforeach()

message("C labs: ${TOTAL_C_LABS_COUNT}")
message("CXX labs: ${TOTAL_CXX_LABS_COUNT}")