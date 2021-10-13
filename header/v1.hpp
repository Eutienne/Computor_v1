/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.hpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:08:34 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/13 18:20:06 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef V1_HPP
# define V1_HPP

# include <iostream>
# include <string>
# include <vector>
# include <cstdlib>

struct ABCD
{
    float   A, B, C;
    long double D;
    int     Degree;
    float   solution1, solution2;
};



class v1
{
public:
    v1(std::string str);
    v1(v1 const & other);

    v1  operator=(v1 const & other);
    
    // void    print_reduce_degree();
    void    print();
    void    reduceform();
    std::string    find_degree(std::string::const_iterator & it);
    void    find_token(std::string const & str);
    std::string::const_iterator store_diget(std::string::const_iterator it, bool sign);
    void    setnbr(std::string const &str, float n);
    // void    solution();
    // float   square_root();
    // long double   square_root(long double d);
    
    
    void    setSolution();
    void    setSolution(float f);
    void    setD();


    
    float&          get_A();
    float&          get_B();
    float&          get_C();
    long double&    get_D();
    int             get_Degree();
    float&          get_solution1();
    float&          get_solution2();




    ~v1();
private:
    v1();
    std::string _mStr;
    std::vector<std::pair<float, std::string> > _mReduce;
    ABCD        _mForm;
    void    setSolution1(float f);
    void    setSolution2(float f);
    void    print2();
};
#endif
