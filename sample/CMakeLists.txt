#Find SFML
if(WEBGUI_BUILD_STATIC)
	set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.3 COMPONENTS window system graphics REQUIRED)
find_package(OpenGL)

set(SOURCE_SAMPLE	main.cpp
					renderer.cpp
					renderer.hpp
					flextGL.c
					flextGL.h
)

add_executable(sample ${SOURCE_SAMPLE})

if(WEBGUI_BUILD_STATIC)
	set_target_properties(sample PROPERTIES
        COMPILE_DEFINITIONS SFML_STATIC)
endif()

set_property(TARGET sample PROPERTY CXX_STANDARD 14)
target_link_libraries(sample webgui ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} 
					${OPENGL_gl_LIBRARY} ${CMAKE_DL_LIBS})
target_include_directories(sample PUBLIC ${SFML_INCLUDE_DIR})