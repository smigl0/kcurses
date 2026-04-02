cmake_minimum_required(VERSION 3.31.11)
project(kcurses VERSION 0.1)

add_executable(kcurses)

target_sources(kcurses 
    PRIVATE
    main.cpp
)

target_link_libraries(kcurses
    PRIVATE
    cursesw
    fmt
)
