PROJECT( util )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(string1 string1.cpp)
ADD_EXECUTABLE(string2 string2.cpp)
ADD_EXECUTABLE(string_test string_test.cpp)
ADD_EXECUTABLE(stringnumconv1 stringnumconv1.cpp)
ADD_EXECUTABLE(stringiter1 stringiter1.cpp)
ADD_EXECUTABLE(stringiter2 stringiter2.cpp)
ADD_EXECUTABLE(string3 string3.cpp)

#target_link_libraries( main Test )
