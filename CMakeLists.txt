cmake_minimum_required(VERSION 3.16)

project(LoggiBUD)
set(Loggibud_VERSION 1.0.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

find_package(RapidJSON REQUIRED)

include(GNUInstallDirs)
include(GenerateExportHeader)

# File groups
file(GLOB LOGGIBUD_SCHEMAS "schemas/*.schema.json")
file(GLOB LOGGIBUD_HEADERS "include/loggibud/*.h")
file(GLOB LOGGIBUD_JSON_HEADERS "include/loggibud/json/*.h")
file(GLOB LOGGIBUD_SOURCES "src/*.cpp")

include_directories(loggibud PUBLIC include)

# Target libloggibud.a
add_library(loggibud ${LOGGIBUD_SOURCES})
target_compile_options(loggibud PUBLIC -Wall -Wextra -Wunused)

generate_export_header(loggibud)
set_property(TARGET loggibud PROPERTY VERSION ${Loggibud_VERSION})

# Compile examples. Use -DBUILD_EXAMPLES=ON
if(BUILD_EXAMPLES)
  message(STATUS "Examples will be compiled")
  add_subdirectory(examples)
else()
  message(STATUS "Examples not will be compiled")
endif()

# Copy all artifacts to a dist directory. Use -DLOCAL=ON
if(LOCAL)
  set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/dist)
  message(STATUS "Local build: artifacts will saved in dist directory")
endif()


install(TARGETS loggibud EXPORT LoggibudTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR} 
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

set(SCHEMAS_DIR "${${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_DATAROOTDIR}/loggibud/schemas}")

add_definitions(
  -DLOGGIBUD_SCHEMAS_DIR=${SCHEMAS_DIR}
)
install(# Schemas
  FILES ${LOGGIBUD_SCHEMAS}
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/loggibud/schemas
)
install(# Headers 
  FILES ${LOGGIBUD_HEADERS} 
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/loggibud
)
install(# Headers (json)
  FILES ${LOGGIBUD_JSON_HEADERS} 
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/loggibud/json
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/Loggibud/LoggibudConfigVersion.cmake"
  VERSION ${Loggibud_VERSION}
  COMPATIBILITY AnyNewerVersion
)

export(EXPORT LoggibudTargets
  FILE "${CMAKE_CURRENT_BINARY_DIR}/Loggibud/LoggibudTargets.cmake"
  NAMESPACE Loggibud::
)
configure_file(cmake/LoggibudConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/Loggibud/LoggibudConfig.cmake"
  @ONLY
)

set(ConfigPackageLocation lib/cmake/Loggibud)
install(EXPORT LoggibudTargets
  FILE
    LoggibudTargets.cmake
  NAMESPACE
    Loggibud::
  DESTINATION
    ${ConfigPackageLocation}
)

install(FILES
  "${CMAKE_CURRENT_BINARY_DIR}/Loggibud/LoggibudConfig.cmake"
  "${CMAKE_CURRENT_BINARY_DIR}/Loggibud/LoggibudConfigVersion.cmake"
  DESTINATION
    ${ConfigPackageLocation}
  COMPONENT
    Devel
)
