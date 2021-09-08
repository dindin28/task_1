cmake_minimum_required(VERSION 3.10)

project(task_1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#========================
#Headers
#========================
set(headers_path "${PROJECT_SOURCE_DIR}/include")

#========================
#Sources
#========================
set(sources_path "${PROJECT_SOURCE_DIR}/src")

set(srcs
    ${sources_path}/date.cpp
    ${sources_path}/main.cpp)

#========================
#Building executable
#========================
add_executable(${PROJECT_NAME} ${srcs})

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
    ${headers_path}
)