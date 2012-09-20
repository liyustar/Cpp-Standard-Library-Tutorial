PROJECT( util )
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

find_package( Boost 1.51 COMPONENTS regex )
# INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
# FIND_PACKAGE(Boost)
IF (Boost_FOUND)
	INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
	ADD_EXECUTABLE(regex1 regex1.cpp)
	target_link_libraries( regex1 ${Boost_LIBRARIES} )
	ADD_EXECUTABLE(regex2 regex2.cpp)
	target_link_libraries( regex2 ${Boost_LIBRARIES} )
	ADD_EXECUTABLE(regex3 regex3.cpp)
	target_link_libraries( regex3 ${Boost_LIBRARIES} )
	# ADD_DEFINITIONS( "-DHAS_BOOST" )
ENDIF()

# SET(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "/usr/local/lib" )

#add_subdirectory( src )

#SET (CMAKE_CXX_FLAGS_INIT "-std=c++0x")
# add_definitions("-g -std=c++0x")
add_definitions("-std=c++0x")
AUX_SOURCE_DIRECTORY(. DIR_SRCS)

#target_link_libraries( main Test )
