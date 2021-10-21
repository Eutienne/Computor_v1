/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:05:32 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/21 18:05:12 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/v1.hpp"

void all_spaces(std::string const & s)
{
   for (std::string::const_iterator it = s.begin(); it != s.end(); it++)
   {
      if( *it != ' ' )
        return ;
   }
   throw std::runtime_error("Error: ALL whitespaces");
}

void    checker(std::string const & s)
{
    int i = 0, point = 0;
    
    try{
        if (s.empty())
            throw std::runtime_error("Error: empty string! B");
        all_spaces(s);

        for(std::string::const_iterator it = s.begin(); it != s.end(); it++)
        {
            if (*it == '.' && ((!isdigit(*(it +1))) || (!isdigit(*(it -1)))))
                throw std::runtime_error("Error: Wrong Format a");
            else if (*it == '.')
                point++;
            if (*it == '=')
                i++;
            if (*it == ' ')
                point = 0;
            if (point > 1)
                throw std::runtime_error("Error: Wrong Format Point");
        }
        if (i != 1)
            throw std::runtime_error("Error: Wrong Format");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    }
   
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return 0;
    checker(argv[1]);
    v1  V(argv[1]);
    float   sqr;

    if (V.getDegree()  == 1)
        V.setSolution();
    else if (V.getDegree() == 2)
    {
        try
        {
            V.setD();
            V.setSqr();
            if (V.getD() >= 0)
                V.setSolution(V.getSqr());            
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    V.print();
    return 0;
}