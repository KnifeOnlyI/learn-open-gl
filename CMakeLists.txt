cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME LearnOpenGL)
set(PROJECT_DESCRIPTION "${PROJECT_NAME}")
set(PROJECT_VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} DESCRIPTION ${PROJECT_DESCRIPTION})

file(
    GLOB_RECURSE
    SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/core/src/*.c
    ${CMAKE_CURRENT_LIST_DIR}/core/src/*.cpp
)

file(
    GLOB_RECURSE
    HEADERS
    ${CMAKE_CURRENT_LIST_DIR}/core/include/*.h
    ${CMAKE_CURRENT_LIST_DIR}/core/include/*.hpp
    ${CMAKE_CURRENT_LIST_DIR}/core/include/*.inl
)

find_package(Boost REQUIRED)
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

if (NOT BOOST_FOUND)
    message(FATAL_ERROR "Not found Boost library")
elseif (NOT SDL2_FOUND)
    message(FATAL_ERROR "Not found SDL2 library")
elseif (NOT OpenGL_FOUND)
    message(FATAL_ERROR "Not found OpenGL library")
endif ()

include_directories(${CMAKE_CURRENT_LIST_DIR}/core/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${Boost_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${CMAKE_DL_LIBS})
