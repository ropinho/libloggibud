cmake_minimum_required(VERSION 3.16)
project(LoggiBUD-Types VERSION "1.0")

include(GNUInstallDirs)

add_subdirectory(examples)

file(GLOB LOGGIBUD_TYPES_HEADERS "src/*.h")
# file(GLOB LOGGIBUD_TYPES_SOURCES "src/*.cpp")

install(
    FILES LOGGIBUD_TYPES_HEADERS 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/loggibud/v1/types
)
