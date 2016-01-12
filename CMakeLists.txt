cmake_minimum_required(VERSION 3.1)

project(webgui)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

if(WIN32)
	add_definitions(-DLITEHTML_UTF8)
endif()
add_subdirectory(litehtml)

set(SOURCE_WEBGUI  	src/webcore.cpp					
					src/webview.cpp					
					src/doc_container.cpp
					src/doc_container.hpp
					src/stb_image.h
					src/stb_truetype.h
					include/webgui/webview.hpp
					include/webgui/webcore.hpp
					include/webgui/renderInterface.hpp
					include/webgui/webgui.hpp
					include/webgui/visibility.hpp
)

#Build Webgui sample
set (WEBGUI_BUILD_SAMPLE FALSE CACHE BOOL "TRUE to build sample of webgui")

#Allow static library on windows
set (WEBGUI_BUILD_STATIC FALSE CACHE BOOL "TRUE to build static version of webgui")

if(WEBGUI_BUILD_STATIC)
	add_library(webgui STATIC ${SOURCE_WEBGUI})
	set_target_properties(webgui PROPERTIES
		COMPILE_DEFINITIONS LITEHTML_UTF8
        COMPILE_DEFINITIONS WEBGUI_STATIC)
else()
	add_library(webgui SHARED ${SOURCE_WEBGUI})
	set_target_properties(webgui PROPERTIES
        COMPILE_DEFINITIONS LITEHTML_UTF8)
endif()

target_include_directories(webgui PUBLIC litehtml/include)

target_link_libraries(webgui litehtml)
#Use C++ 14
set_property(TARGET webgui PROPERTY CXX_STANDARD 14)

if(WEBGUI_BUILD_SAMPLE)
	add_subdirectory(sample)
endif()
