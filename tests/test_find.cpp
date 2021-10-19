/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_find.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 10:12:56 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/19 10:18:27 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../header/v1.hpp"

TEST(Find, Degree)
{
    std::string str = "5 * X^3 + 4 * X^1 + 0 * X^2 = 4 * X^0";
    std::string::const_iterator it = str.begin();
    v1  V(str);

    ASSERT_EQ(V.find_degree(it), "3");
}