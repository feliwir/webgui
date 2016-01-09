#Find SFML
find_package(SFML 2.3 COMPONENTS window system graphics REQUIRED)

set(SOURCE_SAMPLE	main.cpp
)

add_executable(sample ${SOURCE_SAMPLE})

if(WEBGUI_BUILD_STATIC)
	set_target_properties(webgui PROPERTIES
        COMPILE_DEFINITIONS SFML_STATIC)
endif()

target_link_libraries(sample webgui ${SFML_LIBRARIES} ${LiteHTML_LIBRARIES})
target_include_directories(sample PUBLIC ${SFML_INCLUDE_DIR})