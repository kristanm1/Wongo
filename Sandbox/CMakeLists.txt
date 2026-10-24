cmake_minimum_required(VERSION 3.23)

project(Sandbox LANGUAGES CXX)

add_executable(Sandbox)

target_compile_features(Sandbox PUBLIC cxx_std_20)

target_sources(Sandbox
  PRIVATE
    src/SandboxApp.cpp
    src/TestLayer.cpp)

target_link_libraries(Sandbox
  PRIVATE
    CommonDefinitions
    Wongo)

add_custom_command(TARGET Sandbox POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:Wongo>
    $<TARGET_FILE_DIR:Sandbox>)
