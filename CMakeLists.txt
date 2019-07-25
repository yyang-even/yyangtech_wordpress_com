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


enable_testing()
include(CTest)
mark_as_advanced(BUILD_TESTING)


#[==[
#   Function to create a symbolic link in current binary directory to the same file in the source
#]==]
function (CreateSymbolicLinkInCurrentBinaryDir filename)
    # Do nothing if building in-source
    if (${CMAKE_CURRENT_BINARY_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
        return()
    endif()

    # Delete symlink if it exists
    file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/${filename}")

    # Get OS dependent path to use in `execute_process`
    file(TO_NATIVE_PATH "${CMAKE_CURRENT_BINARY_DIR}/${filename}" link)
    file(TO_NATIVE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/${filename}" target)

    set(cmd ln -s ${target} ${link})

    execute_process(COMMAND ${cmd}
        RESULT_VARIABLE result
        ERROR_VARIABLE output)

    if (NOT ${result} EQUAL 0)
        message(FATAL_ERROR "Could not create symbolic link for: ${target} --> ${output}")
    endif()
endfunction(CreateSymbolicLinkInCurrentBinaryDir)

function (AddPythonTest name)
    set(filename ${name}.py)
    CreateSymbolicLinkInCurrentBinaryDir(${filename})
    add_test(Python.${name} ${filename})
endfunction(AddPythonTest)


add_subdirectory(2018_12_27)
add_subdirectory(2019_02_26)
add_subdirectory(2019_07_11)
