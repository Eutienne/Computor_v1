# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    CMakeLists.txt                                     :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <eutrodri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/06 13:24:45 by eutrodri      #+#    #+#                  #
#    Updated: 2021/10/08 23:13:06 by eutrodri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.16.0)

# set the project name
project(computor)

set(CMAKE_CXX_STANDARD 14)

# add the executable
add_executable(computor 
    src/main.cpp
    src/v1.cpp)
    
target_link_libraries(computor PUBLIC
    -pedantic)

# tell cmake that there is unittest
enable_testing()

set(Headers
    header/v1.hpp)

set(Sources
    src/main.cpp
    src/v1.cpp)

add_subdirectory(tests)

add_subdirectory(ThirdParty/gtest)

add_library(computor_lib STATIC ${Sources} ${Headers})

