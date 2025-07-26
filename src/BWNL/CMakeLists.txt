cmake_minimum_required(VERSION 3.15)
project(BWNL)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/lib/curl/include)

add_executable(BWNL src/main.cpp)

target_link_libraries(BWNL PRIVATE
    C:/Users/nerdb/Desktop/coding-projects/bassil/src/BWNL/lib/curl/lib/libcurl.lib
    ws2_32
    wldap32
    crypt32
    advapi32
)

message(STATUS "Source dir: ${CMAKE_SOURCE_DIR}")
