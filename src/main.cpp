/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:05:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/13 18:10:27 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/v1.hpp"
#include <iomanip>
#include <cmath>
#include <cstring>

long double    square_root(long double d)
{
    long double i = 0.0;
    for (; i*i <= d; i++){
        if (i*i == d)
            return i;
    }

    for (long double j = i + 0.1;i*i > d && i != j; j = i, i = i - 0.1);
    for (long double j = i - 0.01; i*i < d && i != j; j = i, i = i + 0.01);
    for (long double j = i + 0.001; i*i > d && i != j; j = i, i = i - 0.001);
    for (long double j = i - 0.0001; i*i < d && i != j; j = i, i = i + 0.0001);
    for (long double j = i + 0.00001; i*i > d && i != j; j = i, i = i - 0.00001);
    for (long double j = i - 0.000001; i*i < d && i != j; j = i, i = i + 0.000001);
    for (long double j = i + 0.0000001; i*i > d && i != j; j = i, i = i - 0.0000001);
    for (long double j = i - 0.00000001; i*i < d && i != j; j = i, i = i + 0.00000001);
    for (long double j = i + 0.000000001; i*i > d && i != j; j = i, i = i - 0.000000001);
    for (long double j = i - 0.0000000001; i*i < d && i != j; j = i, i = i + 0.0000000001);
    for (long double j = i + 0.00000000001; i*i > d && i != j; j = i, i = i - 0.00000000001);
 
    return (i);
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    v1  V(argv[1]);
    float   sqr;


    if (V.get_Degree()  == 1)
        V.setSolution();
    else if (V.get_Degree() == 2)
    {
        try
        {
            V.setD();
            sqr = square_root(V.get_D());
            if (V.get_D() >= 0)
                V.setSolution(sqr);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    V.print();
    return 0;
}