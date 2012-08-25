PROJECT( pair1 )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(pair1 pair1.cpp)
ADD_EXECUTABLE(pair_test pair_test.cpp)
ADD_EXECUTABLE(tuple1 tuple1.cpp)
ADD_EXECUTABLE(tuple2 tuple2.cpp printtuple.hpp )


#target_link_libraries( main Test )
