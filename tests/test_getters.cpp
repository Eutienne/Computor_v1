/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_getters.cpp                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/15 14:16:42 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/18 19:07:32 by eutrodri      ########   odam.nl         */
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

TEST(Getter, D)
{
    v1  V("2.3 * X^1 - 9.8 * X^1 = 5 * X^2 + 3.333 * X^1");

    EXPECT_EQ(V.getD(), 0);

    V.setD();
    ASSERT_EQ(V.getD(), (V.getB() * V.getB()) - 4 * V.getA() * V.getC());
}

TEST(Getter, Degree)
{
    v1  V("2.3 * X^1 - 9.8 * X^1 = 5 * X^7 + 3.333 * X^1");

    ASSERT_EQ(V.getDegree(), 7);
}

TEST(Getter, Solution)
{
    {
        v1 V("5 * X^0 + 4 * X^1 = 4 * X^0");

        EXPECT_EQ(V.getSolution1(), 0);
        EXPECT_EQ(V.getSolution2(), 0);

        V.setSolution();

        ASSERT_EQ(V.getSolution1(), -0.25);
        ASSERT_EQ(V.getSolution2(), 0);
    }
}

TEST(Getter, Solution1)
{
    {
        v1 V("3.3 * X^2 = - 5 * X^1 + 3 * X^2");
        float   sqr;

        EXPECT_EQ(V.getSolution1(), 0);
        EXPECT_EQ(V.getSolution2(), 0);

        V.setD();
        sqr = square_root(V.getD());
        if (V.getD() >= 0)
            V.setSolution(sqr);

        ASSERT_EQ(V.getSolution1(), ((- V.getB()) - sqr) / (2 * V.getA()));
        ASSERT_EQ(V.getSolution2(), 0);
    }
}
