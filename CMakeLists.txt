cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 20)

set(TOTAL_LABS_COUNT 0)

file(GLOB_RECURSE SRC_FILES "labs/*.c*")

project(CppLabs LANGUAGES C CXX)

include(cmake/SetupTargetWarnings.cmake)

foreach(SRC_FILE IN LISTS SRC_FILES)
    string(REPLACE ".c*" "" LAB_TASK_NAME ${SRC_FILE})
    string(REPLACE "${CMAKE_SOURCE_DIR}/labs/" "" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(REPLACE "/" "_" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(TOUPPER ${LAB_TASK_NAME} LAB_TASK_NAME)
    add_executable(${LAB_TASK_NAME} ${SRC_FILE})
    setup_target_warnings(${LAB_TASK_NAME})
    target_include_directories(${LAB_TASK_NAME} PUBLIC "${CMAKE_SOURCE_DIR}/common_includes")
    math(EXPR TOTAL_LABS_COUNT ${TOTAL_LABS_COUNT}+1)
endforeach()

message("Total labs: ${TOTAL_LABS_COUNT}")