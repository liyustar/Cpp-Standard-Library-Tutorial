PROJECT( fo )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(foreach1 foreach1.cpp)
ADD_EXECUTABLE(foreach2 foreach2.cpp)
ADD_EXECUTABLE(foreach3 foreach3.cpp)
ADD_EXECUTABLE(count1 count1.cpp)
ADD_EXECUTABLE(minmax1 minmax1.cpp)

#target_link_libraries( main Test )
