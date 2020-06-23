cmake_minimum_required(VERSION 3.5)
project(Diary VERSION 0.1 LANGUAGES CXX )

# set the compiling flags
set ( CMAKE_CXX_FLAGS "-Wall" )

#--------------------------------
# This is for old cmake versions
#set (CMAKE_CXX_STANDARD 11)
#--------------------------------

### [1] Application target
# set the include path
include_directories( include )

# define the sources for the project
add_executable( diary
                src/main.cpp
                src/App.cpp
                src/Date.cpp
                src/Diary.cpp
                src/Message.cpp
                src/Time.cpp )

# define C++11 standard
set_property(TARGET diary PROPERTY CXX_STANDARD 11)

# The end
