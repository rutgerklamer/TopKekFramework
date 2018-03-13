# CMake entry point
cmake_minimum_required (VERSION 2.6)
project (TKF)


OPTION(MAKE_DEMO "Make TKF demo application" ON)

# Compile external dependencies
find_package(OpenGL REQUIRED)

add_subdirectory (ExtLibs)

include_directories(
	${CMAKE_SOURCE_DIR}/ExtLibs/glfw-3.2.1/include/GLFW
	${CMAKE_SOURCE_DIR}/ExtLibs/glew-2.1.0/include
	${CMAKE_SOURCE_DIR}/ExtLibs/glm-0.9.8.4
	${CMAKE_SOURCE_DIR}/ExtLibs/SOIL2/${HEADERS}
	${CMAKE_SOURCE_DIR}/ExtLibs
	${CMAKE_SOURCE_DIR}/TKF
	${CMAKE_SOURCE_DIR}/.
)

link_directories(
	${CMAKE_SOURCE_DIR}/ExtLibs/glfw-3.2.1/src
	${CMAKE_SOURCE_DIR}/ExtLibs/glew-2.1.0/lib
	${CMAKE_SOURCE_DIR}/TKF
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	TKF
	glfw
	glew
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

####################################################################
# libTKF.a                                                        #
####################################################################
add_library(TKF
	TKF/camera.cpp
	TKF/camera.h
	TKF/config.h
	TKF/inputmanager.cpp
	TKF/inputmanager.h
	TKF/object2d.cpp
	TKF/object2d.h
	TKF/renderer.cpp
	TKF/renderer.h
	TKF/scene.cpp
	TKF/scene.h
	TKF/shader.cpp
	TKF/shader.h
	TKF/sprite.cpp
	TKF/sprite.h
	TKF/window.cpp
	TKF/window.h
	
	
)
file(
	COPY ${CMAKE_SOURCE_DIR}/TKF/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY ${CMAKE_SOURCE_DIR}/TKF/fonts
	DESTINATION ${CMAKE_BINARY_DIR}
)

####################################################################
# demo               	                                          #
####################################################################
IF(MAKE_DEMO)
	add_executable(DEMO
		DEMO/main.cpp
	)
	target_link_libraries(DEMO
		${ALL_GRAPHICS_LIBS}
	)
	# Copy assets to the build directory
	file(
		COPY DEMO/assets
		DESTINATION ${CMAKE_BINARY_DIR}
	)
ENDIF()
