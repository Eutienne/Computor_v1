/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:05:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/12 20:07:30 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "v1.hpp"
#include <iomanip>

int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    v1  V(argv[1]);

    std::cout << std::setprecision(10) << V.square_root(43494.3455) << std::endl;

    // V.print();

    return 0;
}