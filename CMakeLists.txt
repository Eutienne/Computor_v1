# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    CMakeLists.txt                                     :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <eutrodri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/06 13:24:45 by eutrodri      #+#    #+#                  #
#    Updated: 2021/10/06 13:28:33 by eutrodri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_STANDARD 14)

# set the project name
project(computor)

# add the executable
add_executable(computor 
    main.cpp
    v1.cpp)
    
target_link_libraries(computor PUBLIC
    -pedantic)

# tell cmake that there is unittest
enable_testing()

set(Headers
    v1.hpp)

set(Sources
    main.cpp)

add_subdirectory(ThirdParty/gtest)

#add_library(computor STATIC ${Sources} ${Headers})

add_subdirectory(tests)