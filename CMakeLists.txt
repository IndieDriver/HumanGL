cmake_minimum_required(VERSION 3.5)
project(HumanGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++14")

find_package(OpenGL REQUIRED)
find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(Classes)
include_directories(include)

SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(SOURCE_FILES
	src/main.cpp
	Classes/env.cpp
	Classes/Vec.cpp
	Classes/Matrix.cpp
	Classes/Shader.cpp
	Classes/Model.cpp
	Classes/Membre.cpp
	Classes/Animation.cpp
	Classes/Animator.cpp
	Classes/Skeleton.cpp
	)

add_executable(HumanGL ${SOURCE_FILES})

target_link_libraries(HumanGL ${SDL2_LIBRARIES})
target_link_libraries(HumanGL ${OPENGL_LIBRARIES})
