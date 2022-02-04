cmake_minimum_required(VERSION 3.22)

project(main)

include_directories("inc")

add_executable(${PROJECT_NAME} src/main.c)
