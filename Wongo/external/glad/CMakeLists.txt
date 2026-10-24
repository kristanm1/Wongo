cmake_minimum_required(VERSION 3.23)

project(glad)

add_library(glad STATIC)

target_sources(glad
  PRIVATE
    src/gl.c
  
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/glad/gl.h)
