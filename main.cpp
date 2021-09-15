/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:05:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/09/15 19:55:08 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "v1.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    v1  V(argv[1]);

    // V.print();

    return 0;
}