cmake_minimum_required(VERSION 3.23)
project(QtSession1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5 COMPONENTS
  Core
  REQUIRED)
find_package(Qt5 COMPONENTS Sql REQUIRED)


add_executable(QtSession1 main.cpp Student.h)
target_link_libraries(QtSession1
  Qt5::Core
)
target_link_libraries(QtSession1
        Qt5::Sql
        )




