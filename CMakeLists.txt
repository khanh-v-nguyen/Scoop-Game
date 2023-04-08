cmake_minimum_required(VERSION 3.23)
project(iceCreamGame2)

set(CMAKE_CXX_STANDARD 14)

add_executable(iceCreamGame2 main.cpp Position.cpp Position.h MouseEvents.cpp MouseEvents.h FallingScoop.cpp FallingScoop.h Cone.cpp Cone.h Background.cpp Background.h Driver.cpp Driver.h)

target_link_libraries(iceCreamGame2 sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

