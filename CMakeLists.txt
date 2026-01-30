cmake_minimum_required(VERSION 3.20)

project(engine C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

find_package(raylib REQUIRED)

add_executable(engine
  src/main.c
  src/core/engine.c
  src/plataform/plataform.c  
)

target_include_directories(engine PRIVATE src)
target_link_libraries(engine raylib m)