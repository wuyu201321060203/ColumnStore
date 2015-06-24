CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT(CS C CXX)

IF(NOT BUILD_TYPE)
    SET(BUILD_TYPE "DEBUG")
ENDIF()

SET(CXX_FLAGS
    -ggdb3
    -Wall
    -Wextra
    -pthread
    -Wno-unused-parameter
    -Woverloaded-virtual
    -Wpointer-arith
    -march=native
    -rdynamic
    -std=c++11)

STRING(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
#SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -DCSDEBUG -DSPEEDTEST")
#SET(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -DCSDEBUG")
SET(CMAKE_CXX_FLAGS_RELEASE "-O2 ")

SET(CMAKE_CXX_COMPILER "g++")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

FIND_PATH(MUDUO_DEBUG_PATH libmuduo_net_cpp11.a /home/build/debug-install/lib)
FIND_PATH(MUDUO_RELEASE_PATH libmuduo_net_cpp11.a /home/build/release-install/lib)

IF(NOT MUDUO_DEBUG_PATH AND NOT MUDUO_RELEASE_PATH)
    MESSAGE(STATUS "can't find muduo path")
ELSE()
    MESSAGE(STATUS "muduo path found")
ENDIF()

FIND_LIBRARY(MUDUO_NET_CPP11 libmuduo_net_cpp11.a /usr/lib /usr/local/lib
    ${MUDUO_DEBUG_PATH} ${MUDUO_RELEASE_PATH})
FIND_LIBRARY(MUDUO_BASE_CPP11 libmuduo_base_cpp11.a /usr/lib /usr/local/lib
    ${MUDUO_DEBUG_PATH} ${MUDUO_RELEASE_PATH})

FIND_LIBRARY(GTEST gtest /home/gtest-1.7.0/build/)

FIND_LIBRARY(COMMON common /home/common/lib)

IF(NOT MUDUO_NET_CPP11)
    MESSAGE(FATAL_ERROR "lib muduo_net_cpp11 not found")
ELSE()
    MESSAGE(STATUS "lib muduo_net_cpp11 found ${MUDUO_NET_CPP11}")
ENDIF()

IF(NOT MUDUO_BASE_CPP11)
    MESSAGE(FATAL_ERROR "lib muduo_base_cpp11 not found")
ELSE()
    MESSAGE(STATUS "lib muduo_base_cpp11 found ${MUDUO_BASE_CPP11}")
ENDIF()

IF(NOT GTEST)
    MESSAGE(FATAL_ERROR "lib gtest not found")
ELSE()
    MESSAGE(STATUS "lib gtest found ${GTEST}")
ENDIF()

IF(NOT GTEST)
    MESSAGE(FATAL_ERROR "lib common not found")
ELSE()
    MESSAGE(STATUS "lib common found ${COMMON}")
ENDIF()

FIND_PACKAGE(Protobuf)

MESSAGE(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})
ADD_SUBDIRECTORY(CS/src/CS)

INSTALL(FILES README DESTINATION share/doc/CS)
