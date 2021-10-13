# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    CMakeLists.txt                                     :+:    :+:             #
#                                                      +:+                     #
#    By: eutrodri <eutrodri@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/10/06 13:29:26 by eutrodri      #+#    #+#                  #
#    Updated: 2021/10/08 19:46:19 by eutrodri      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.16.0)

set(CMAKE_CXX_STANDARD 14)

# set the project name
project(computor_test)


set(Sources
    test_computor.cpp
    test.cpp)

# add the executable
add_executable(computor_test ${Sources})



add_test(
    NAME computor_test
    COMMAND computor_test
)
target_link_libraries(computor_test PUBLIC 
    computor_lib gtest_main
)