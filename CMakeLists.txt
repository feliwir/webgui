cmake_minimum_required(VERSION 3.1)

project(webgui)

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

#Find LiteHTML
find_package(LiteHTML REQUIRED)

set(SOURCE_WEBGUI  	src/webcore.cpp
					src/webcore.hpp
					src/webview.cpp
					src/webview.hpp
					src/doc_container.cpp
					src/doc_container.hpp
					src/stb_image.h
					src/stb_truetype.h
					include/renderInterface.hpp
					include/webgui.hpp
)

#Build Webgui sample
set (WEBGUI_BUILD_SAMPLE FALSE CACHE BOOL "TRUE to build sample of webgui")

#Allow static library on windows
if (${CMAKE_HOST_WIN32})
    set (WEBGUI_BUILD_STATIC FALSE CACHE BOOL "TRUE to build static version of webgui")
endif()


if(WEBGUI_BUILD_STATIC)
	add_library(webgui STATIC ${SOURCE_WEBGUI})
else()
	add_library(webgui SHARED ${SOURCE_WEBGUI})
endif()

target_include_directories(webgui PUBLIC ${LiteHTML_INCLUDE_DIRS})

target_link_libraries(webgui ${LiteHTML_LIBRARIES})
#Use C++ 14
set_property(TARGET webgui PROPERTY CXX_STANDARD 14)
