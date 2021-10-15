/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_computor.cpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 21:08:57 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/15 13:13:23 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../header/v1.hpp"

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

TEST(getters, getA)
{
    std::string str = "5 * X^1 + 4 * X^1 + 0 * X^2 = 4 * X^0";
    std::string::const_iterator it = str.begin();
    v1  V(str);

    ASSERT_EQ(V.getA(), 0);
}