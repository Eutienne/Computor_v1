/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.hpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:08:34 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/11 17:38:26 by eutrodri      ########   odam.nl         */
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
    float   A, B, C, D;
    int     Degree;
};



class v1
{
public:
    v1(std::string str);
    v1(v1 const & other);

    v1  operator=(v1 const & other);
    
    void    print_reduce_degree();
    void    reduceform();
    std::string    find_degree(std::string::const_iterator & it);
    void    find_token(std::string const & str);
    std::string::const_iterator store_diget(std::string::const_iterator it, bool sign);
    void    setnbr(std::string const &str, float n);
    void    solution();
    float   square_root();
    
    
    float&  get_A();
    float&  get_B();
    float&  get_C();
    float&  get_D();
    int     get_Degree();




    ~v1();
private:
    v1();
    std::string _mStr;
    std::vector<std::pair<float, std::string> > _mReduce;
    ABCD        _mForm;
};
#endif
