cmake_minimum_required(VERSION 3.16)
project(LoggiBUD-Types)

file(GLOB LOGGIBUD_TYPES_HEADERS "src/*.h")

include(GNUInstallDirs)
install(
    FILES LOGGIBUD_TYPES_HEADERS 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/loggibud/v1/types
)
