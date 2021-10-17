cmake_minimum_required(VERSION 3.16)

message(STATUS "Examples will be compiled in ${CMAKE_CURRENT_SOURCE_DIR}")

include_directories(../include)
link_libraries(loggibud)

add_executable(json-to-point    json-to-point.cpp)
add_executable(json-to-delivery json-to-delivery.cpp)
add_executable(parse-instance   parse-instance.cpp)

install(
    TARGETS json-to-point json-to-delivery parse-instance
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}
)