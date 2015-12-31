cmake_minimum_required(VERSION 3.1)

project(webgui)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

#Find LiteHTML
find_package(LiteHTML REQUIRED)

set(SOURCE_WEBGUI  src/webcore.cpp
)

add_library(webgui STATIC ${SOURCE_WEBGUI})

#Use C++ 14
set_property(TARGET webgui PROPERTY CXX_STANDARD 14)
