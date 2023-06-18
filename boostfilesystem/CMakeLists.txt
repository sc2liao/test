cmake_minimum_required(VERSION 3.5)
#set(BOOST_ROOT /usr/local/include/boost)
PROJECT(boost_filesystem)



FIND_PACKAGE(Boost COMPONENTS ${BOOST_REQ_LIB} REQUIRED)
#LIST(APPEND BOOST_REQ_LIB "filesystem")

if(Boost_FOUND)
MESSAGE(STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}")
MESSAGE(STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}")
MESSAGE(STATUS "Boost_VERSION = ${Boost_VERSION}")
MESSAGE(STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}")

endif()

set(filesys ${CMAKE_CURRENT_SOURCE_DIR}/boostfilesystem.cpp)

#target_compile_options(boost_fs)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_filesystem")
#LIST(APPEND DORYFS_REQUIRE_LIB ${Boost_LIBRARIES})
#LIST(APPEND DORYFS_REQUIRE_INC ${Boost_INCLUDE_DIRS})
SET(Boost_LIBRARIES /lib/x86_64-linux-gnu/)
add_executable(boost_fs ${filesys})
TARGET_INCLUDE_DIRECTORIES(boost_fs PRIVATE ${Boost_INCLUDE_DIRS})

#TARGET_COMPILE_OPTIONS(boost_fs PRIVATE ${BOOST_REQ_LIB})
target_link_libraries(boost_fs ${Boost_LIBRARIES})

STRING(APPEND CMAKE_EXE_LINKER_FLAGS "-lboost_filesystem")