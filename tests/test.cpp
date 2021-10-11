/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 20:55:08 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/11 15:22:36 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
// #include "test_computor.cpp"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);

    return (RUN_ALL_TESTS());
}