cmake_minimum_required(VERSION 3.5)
project(Diary VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

SET ( SRCS
      src/App.cpp
      src/Date.cpp
      src/Diary.cpp
      src/Message.cpp
      src/Time.cpp
      src/utils.cpp )

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( diary src/main.cpp "${SRCS}" )

# define C++11 standard
set_property(TARGET diary PROPERTY CXX_STANDARD 11)

### [2] Application test
# set the include path
include_directories( include )

# define the sources for the testing
add_executable( run_test test/main.cpp "${SRCS}" )

# define C++11 standard
set_property(TARGET run_test PROPERTY CXX_STANDARD 11)

# The end
