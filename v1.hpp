/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.hpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:08:34 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/09/15 21:56:47 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef V1_HPP
# define V1_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>

class v1
{
public:
    v1(std::string str);
    v1(v1 const & other);

    v1  operator=(v1 const & other);
    
    void    print();
    void    reduceform();
    std::string    find_degree(std::string::const_iterator & it);
    void    find_token(std::string const & str);
    std::string::const_iterator store_diget(std::string::const_iterator it, bool sign);
    void    setnbr(std::string const &str, float n);
    void    solution();




    ~v1();
private:
    v1();
    std::string _mStr;
    int         _mDegree;
    std::vector<std::pair<float, std::string> > _mReduce;
    float       _mA;
    float       _mB;
    float       _mC;

};
#endif
