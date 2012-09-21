PROJECT( io )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(io1 io1.cpp)
ADD_EXECUTABLE(timemanipulator1 timemanipulator1.cpp)

#target_link_libraries( main Test )
