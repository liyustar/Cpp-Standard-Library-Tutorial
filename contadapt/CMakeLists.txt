PROJECT( util )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(stack1 stack1.cpp)
ADD_EXECUTABLE(stack_test stack_test.cpp)
ADD_EXECUTABLE(stack2 stack2.cpp)

#target_link_libraries( main Test )
