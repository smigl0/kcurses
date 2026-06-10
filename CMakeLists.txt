cmake_minimum_required(VERSION 3.31)
project(PDcursesCenterer LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CURSES_NEED_WIDE TRUE)
find_package(Curses REQUIRED)

add_executable(kcurses src/main.cpp)

target_include_directories(kcurses PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(kcurses PRIVATE ${CURSES_LIBRARIES})

configure_file(wordart.txt wordart.txt COPYONLY)
