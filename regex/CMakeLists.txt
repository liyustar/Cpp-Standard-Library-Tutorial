PROJECT( util )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
# add_definitions("-g -std=c++0x")
add_definitions("-std=gnu++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(regex1 regex1.cpp)

#target_link_libraries( main Test )
