cmake_minimum_required(VERSION 3.16)
project(AerialAssaultTrooperPanel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

add_executable(AerialAssaultTrooperPanel
        main.cpp
)

target_link_libraries(AerialAssaultTrooperPanel
        Qt6::Widgets
)
