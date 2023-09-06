cmake_minimum_required(VERSION 3.20)

project(CLabs LANGUAGES C)

file(GLOB_RECURSE C_FILES "labs/*.c")

foreach(C_FILE IN LISTS C_FILES)
    string(REPLACE ".c" "" LAB_TASK_NAME ${C_FILE})
    string(REPLACE "${CMAKE_SOURCE_DIR}/labs/" "" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(REPLACE "/" "_" LAB_TASK_NAME ${LAB_TASK_NAME})
    string(TOUPPER ${LAB_TASK_NAME} LAB_TASK_NAME)
	add_executable(${LAB_TASK_NAME} ${C_FILE})
endforeach()

