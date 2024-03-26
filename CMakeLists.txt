cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

project(
    "FirstExec"
    VERSION 1.1.0
    DESCRIPTION "Laboratorio 1 Sistemas Operativos 2"
    LANGUAGES C
)

enable_testing()
include(CTest)

set(CMAKE_C_STANDARD 17)

include_directories("include")

include(FetchContent)

set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

FetchContent_MakeAvailable(Unity)

file(GLOB_RECURSE SOURCES "src/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

add_subdirectory(lib/libdyn)
add_subdirectory(lib/libstat)

target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libstat/include)

target_link_libraries(${PROJECT_NAME} StaticCLib DynamicCLib)

if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(test)
endif()
