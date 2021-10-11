/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_computor.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 21:08:57 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/11 14:51:01 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../v1.hpp"

TEST(test_computor, string)
{
    std::string str = "5 * X^0 + 4 * X^1 + 0 * X^2 = 4 * X^0";
    std::string::const_iterator it = str.begin();
    v1  V(str);

    ASSERT_EQ(V.find_degree(it), "0");
}

TEST(test_computor, string2)
{
    std::string str = "5 * X^1 + 4 * X^1 + 0 * X^2 = 4 * X^0";
    std::string::const_iterator it = str.begin();
    v1  V(str);

    ASSERT_EQ(V.find_degree(it), "1");
}

TEST(getters, get_A)
{
    std::string str = "5 * X^1 + 4 * X^1 + 0 * X^2 = 4 * X^0";
    std::string::const_iterator it = str.begin();
    v1  V(str);

    ASSERT_EQ(V.get_A(), 0);
}