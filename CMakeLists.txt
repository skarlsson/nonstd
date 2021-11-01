cmake_minimum_required(VERSION 3.5)
project(nonstd-cpp)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

#FEATURES
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wpedantic -Wreturn-type -g -O2")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wpedantic -Wreturn-type -g")

SET(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)
SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
add_definitions(-g -D_FILE_OFFSET_BITS=64 -D_REENTRANT -DEXTERNAL_LOCKS -DMULTITHREAD)
add_definitions(-fPIC)
add_definitions(-Wno-deprecated)

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB HEADERS
        include/nonstd/*.h
    )

SET(ALL_LIBS pthread rt c)

INSTALL(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include)

include(CTest)
enable_testing()
add_subdirectory(tests)

