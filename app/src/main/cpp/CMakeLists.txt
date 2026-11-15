cmake_minimum_required(VERSION 3.22.1)
project("angrytux")

set(CMAKE_CXX_STANDARD 17)

# Include Box2D physics engine
add_subdirectory(box2d)

add_library(angrytux SHARED
    main.cpp
    Core/GameManager.cpp
    Entities/StructureBlock.cpp
)

target_include_directories(angrytux PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities
    ${CMAKE_CURRENT_SOURCE_DIR}/box2d/include
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
