cmake_minimum_required(VERSION 3.1)

project(webgui)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

#Find LiteHTML
find_package(LiteHTML REQUIRED)

set(SOURCE_WEBGUI  	src/webcore.cpp
					src/webview.cpp
					src/doc_container.cpp
)

add_library(webgui SHARED ${SOURCE_WEBGUI})

target_include_directories(webgui PUBLIC ${LiteHTML_INCLUDE_DIRS})

target_link_libraries(webgui ${LiteHTML_LIBRARIES})
#Use C++ 14
set_property(TARGET webgui PROPERTY CXX_STANDARD 14)
