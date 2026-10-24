cmake_minimum_required(VERSION 3.23)

project(Wongo LANGUAGES CXX)

add_library(Wongo STATIC)

add_subdirectory(external/glfw)
add_subdirectory(external/glad)

find_package(OpenGL REQUIRED)

target_compile_features(Wongo PUBLIC cxx_std_20)

target_include_directories(Wongo
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/external/spdlog/include)

target_compile_definitions(Wongo
  PUBLIC
    WONGO_RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/resource")

target_link_libraries(Wongo
  PUBLIC
    CommonDefinitions
    OpenGL::GL
    glfw
    glad)

target_sources(Wongo
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/Wongo.h

      src/Wongo/Core.h
      src/Wongo/Application.h
      src/Wongo/EntryPoint.h
      src/Wongo/Logger.h
      src/Wongo/Window.h
      src/Wongo/Layer.h

      src/Wongo/Utils/Image.h

      src/Wongo/Events/Event.h
      src/Wongo/Events/KeyboardEvent.h
      src/Wongo/Events/MouseEvent.h
      src/Wongo/Events/ScrollEvent.h
      src/Wongo/Events/WindowEvent.h

      src/Wongo/Renderer/Buffer.h
      src/Wongo/Renderer/VertexArray.h
      src/Wongo/Renderer/Program.h
      src/Wongo/Renderer/Shader.h
      src/Wongo/Renderer/Texture.h
      src/Wongo/Renderer/Renderer.h
      src/Wongo/Renderer/Backend.h

  PRIVATE
    src/Wongo/Core.cpp
    src/Wongo/Logger.cpp
    src/Wongo/Application.cpp
    src/Wongo/ImGuiLayer.cpp

    src/Wongo/Utils/Image.cpp

    src/Wongo/Renderer/Buffer.cpp
    src/Wongo/Renderer/Core.cpp    
    src/Wongo/Renderer/VertexArray.cpp
    src/Wongo/Renderer/Shader.cpp
    src/Wongo/Renderer/Program.cpp
    src/Wongo/Renderer/Texture.cpp
    src/Wongo/Renderer/Renderer.cpp

    src/Wongo/Platform/OpenGL/Buffer.cpp
    src/Wongo/Platform/OpenGL/Core.cpp
    src/Wongo/Platform/OpenGL/OpenGLBackend.cpp
    src/Wongo/Platform/OpenGL/Program.cpp
    src/Wongo/Platform/OpenGL/Renderer.cpp
    src/Wongo/Platform/OpenGL/Shader.cpp
    src/Wongo/Platform/OpenGL/Texture.cpp
    src/Wongo/Platform/OpenGL/VertexArray.cpp

    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp)
  
target_include_directories(Wongo
  PRIVATE
    external/tinyobjloader/include
    external/stb/include
    external/imgui/backends)

target_include_directories(Wongo
  PUBLIC
    external/glm/include
    external/imgui)

target_precompile_headers(Wongo
  PRIVATE
    src/Wongo/pch.h)

if (WIN32)
  target_sources(Wongo
    PUBLIC
      src/Wongo/Platform/Windows/WindowsWindow.cpp)
endif()