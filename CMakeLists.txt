cmake_minimum_required(VERSION 3.10)
project(Dungeon VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8 /MTd)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
endif()

set(SDL2_DIR "D:/Libs/SDL/SDL2/cmake")

set(SOURCES
    main.cpp
    Game.cpp
)

set(HEADERS
    Game.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

if(MSVC)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
        LINK_FLAGS_RELEASE "/SUBSYSTEM:CONSOLE"
    )
endif()

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main SDL2::SDL2)