/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:05:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/15 13:25:37 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/v1.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    v1  V(argv[1]);
    float   sqr;

    if (V.getDegree()  == 1)
        V.setSolution();
    else if (V.getDegree() == 2)
    {
        try
        {
            V.setD();
            sqr = square_root(V.getD());
            if (V.getD() >= 0)
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