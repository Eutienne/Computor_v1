/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_getters.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 14:16:42 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/15 14:21:39 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../header/v1.hpp"

TEST(Getter, A)
{
    v1  V("5 * X^2 = 7 * x^0");

    ASSERT_EQ(V.getA(), 5);
}

TEST(Getter, B)
{
    v1  V("5 * X^1 = 7 * x^0");

    ASSERT_EQ(V.getB(), 5);
}

TEST(Getter, C)
{
    v1  V("5 * X^0 = 7 * x^0");

    ASSERT_EQ(V.getC(), -2);
}