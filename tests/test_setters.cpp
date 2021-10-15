/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_setters.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 12:14:29 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/15 14:18:48 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../header/v1.hpp"


TEST(Setters, D)
{
    std::string str = "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0";
    v1  V(str);

    EXPECT_EQ(V.getD(), 0);

    V.setD();
    ASSERT_EQ(V.getD(), (V.getB() * V.getB()) - 4 * V.getA() * V.getC());
}




TEST(Setters, solution)
{
    std::string str = "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0";
    v1  V(str);
    float sqr;

    EXPECT_EQ(V.getSolution1() , 0);
    EXPECT_EQ(V.getSolution2() , 0);

    V.setD();
    sqr = square_root(V.getD());
    if (V.getD() >= 0)
        V.setSolution(sqr);

    ASSERT_FLOAT_EQ(V.getSolution1(), 0.905239);
    ASSERT_NEAR(V.getSolution2(), -0.475131, 0.0000009);
}

TEST(Setters, solution1)
{
    std::string str = "5 * X^0 + 4 * X^1 = 4 * X^0";
    v1  V(str);

    EXPECT_EQ(V.getSolution1() , 0);
    EXPECT_EQ(V.getSolution2() , 0);

    V.setSolution();

    ASSERT_FLOAT_EQ(V.getSolution1(), -0.25);
    ASSERT_FLOAT_EQ(V.getSolution2(), 0);
}
