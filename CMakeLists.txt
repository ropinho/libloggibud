cmake_minimum_required(VERSION 3.16)
project(LoggiBUD-Types VERSION "1.0")

find_package(RapidJSON REQUIRED)

include(GNUInstallDirs)

# File groups
file(GLOB LOGGIBUD_SCHEMAS "schemas/*.schema.json")
file(GLOB LOGGIBUD_HEADERS "include/loggibud/*.h")
file(GLOB LOGGIBUD_SOURCES "src/*.cpp")

# Target libloggibud.a
add_library(loggibud ${LOGGIBUD_SOURCES})
target_include_directories(loggibud PUBLIC include)
target_compile_options(loggibud PUBLIC -Wall -Wextra -Wunused -Werror)

# Compile examples. Use -DBUILD_EXAMPLES=ON
if(BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

# Copy all artifacts to a dist directory. Use -DLOCAL=ON
if(LOCAL)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)
  message(STATUS "Local build: artifacts will saved in ${CMAKE_SOURCE_DIR}/dist")
endif()

install(# Schemas
    FILES ${LOGGIBUD_SCHEMAS}
    DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/loggibud
)
install(# Headers 
    FILES ${LOGGIBUD_HEADERS} 
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/loggibud
)
install(# libloggibud.a
    TARGETS loggibud
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
