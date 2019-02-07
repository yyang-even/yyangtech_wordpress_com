cmake_minimum_required(VERSION 2.8.12.2)

project (yyangtech_wordpress_com)

###################################################
# gcc
###################################################
# Using C++14
set(CMAKE_CXX_FLAGS       "${CMAKE_CXX_FLAGS}       -std=c++1y")
set(CMAKE_CXX_FLAGS       "${CMAKE_CXX_FLAGS}       -g")
# Turn warning about any return statement with no return value in a function whose return type is not void
set(CMAKE_CXX_FLAGS       "${CMAKE_CXX_FLAGS}       -Werror=return-type")

include_directories ("${PROJECT_SOURCE_DIR}")

###################################################
# Options
###################################################
# define option explicitly for pretty ccmake/cmake-gui
option(BUILD_SHARED_LIBS "Build libraries as .dll's/.so's" true)
mark_as_advanced(CLEAR BUILD_SHARED_LIBS)# mark un-advanced

add_subdirectory(2018_12_27)
add_subdirectory(2019_02_26)
