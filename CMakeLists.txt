cmake_minimum_required(VERSION 3.23)

set(CONFIGURATION_TYPES Debug Release)

if(CMAKE_CONFIGURATION_TYPES)
  set(CMAKE_CONFIGURATION_TYPES "${CONFIGURATION_TYPES}"
    CACHE STRING "Available build configurations" FORCE)
elseif(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
elseif(NOT CMAKE_BUILD_TYPE IN_LIST CONFIGURATION_TYPES)
  message(FATAL_ERROR
    "Invalid CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}, allowed build types are ${CONFIGURATION_TYPES}")
endif()

project(WongoProject LANGUAGES CXX)

add_library(CommonDefinitions INTERFACE)

if (WIN32)
  target_compile_definitions(CommonDefinitions
    INTERFACE
      WONGO_PLATFORM_WINDOWS)
endif()

if(MSVC)
  target_compile_options(CommonDefinitions
    INTERFACE
      /utf-8)
endif()

add_subdirectory(Wongo)
add_subdirectory(Sandbox)
