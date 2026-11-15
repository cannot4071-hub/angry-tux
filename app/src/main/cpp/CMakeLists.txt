cmake_minimum_required(VERSION 3.22.1)
project("angrytux")

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
    box2d
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG v2.4.1
)

set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(box2d)

add_library(angrytux SHARED
    main.cpp
    Core/GameManager.cpp
    Entities/StructureBlock.cpp
)

target_include_directories(angrytux PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities
    ${box2d_SOURCE_DIR}/include
)

find_library(log-lib log)
find_library(glesv2-lib GLESv2)
find_library(android-lib android)

target_link_libraries(angrytux
    box2d
    ${log-lib}
    ${glesv2-lib}
    ${android-lib}
)
