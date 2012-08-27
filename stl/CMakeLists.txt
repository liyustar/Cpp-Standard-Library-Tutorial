PROJECT( stl )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(vector1 vector1.cpp)
ADD_EXECUTABLE(deque1 deque1.cpp)
ADD_EXECUTABLE(array1 array1.cpp)
ADD_EXECUTABLE(list1 list1.cpp)
ADD_EXECUTABLE(list2 list2.cpp)
ADD_EXECUTABLE(forwardlist1 forwardlist1.cpp)

#target_link_libraries( main Test )
