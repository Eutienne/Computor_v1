/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.cpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:15:25 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/09/15 17:26:55 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "v1.hpp"

v1::v1()
{
}

v1::v1(std::string str)
    : _mStr(str), _mDegree(0), _mA(0), _mB(0), _mC(0)
{
    this->find_token(_mStr);
    this->print();
    this->solution();
}

v1::v1(v1 const & other)
{
    *this = other;
}

v1 v1::operator=(v1 const & other)
{
    _mStr = other._mStr;
    _mDegree = other._mDegree;
    return *this;
}

void    v1::print()
{

    this->reduceform();
    std::cout << "Polynomial degree: " << _mDegree << std::endl;
}

void    v1::solution()
{
    if (_mDegree > 2)
    {
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
        return ;
    }
    std::cout << "the solution is" << std::endl;
}


void    v1::reduceform()
{
    std::cout << "Reduced form: \"";
    for (size_t i = 0; i < _mReduce.size(); i++)
    {
        if (i != 0 && _mReduce[i].first >= 0)
            std::cout << "+ ";
        else if (i != 0 && _mReduce[i].first <= 0)
        {
            std::cout << "- ";
            if (_mReduce[i].first != 0)
                _mReduce[i].first *= -1;
        } 
        std::cout << _mReduce[i].first << " ";
        std::cout << "* X^";
        std::cout << _mReduce[i].second << " ";
    }
    std::cout << "= 0\"" << std::endl;
}

std::string    v1::find_degree(std::string::const_iterator & it)
{
    std::string str;
    while (*it != '^')
        it++;
    it++;
    while (isdigit(*it))
    {
        str += *it;
        it++;
    }
    if (atof(str.c_str()) > _mDegree)
        _mDegree = atof(str.c_str());
    return str;
}

void    v1::setnbr(std::string const &str, float n)
{
    for (size_t i = 0; i < _mReduce.size(); i++)
    {
        if (_mReduce[i].second == str)
        {
            _mReduce[i].first += n;
            break ;
        }
        else if (i == _mReduce.size() - 1)
        {
            _mReduce.push_back(make_pair(n, str));
            break ;
        }
    }
    if (_mReduce.size() == 0)
        _mReduce.push_back(make_pair(n, str));
    if (atof(str.c_str()) == 0)
        _mC += n;
    else if (atof(str.c_str()) == 1)
        _mB += n;
    else if (atof(str.c_str()) == 2)
        _mA += n;
}


void    v1::find_token(std::string const & str)
{
    bool sign = false;
    for(std::string::const_iterator it = str.begin(); *it != '\0'; it++)
    {
        if (*it == '=')
            sign = true;
        if (isdigit(*it) || *it == '-')
            it = store_diget(it, sign);
    }
}

std::string::const_iterator v1::store_diget(std::string::const_iterator it, bool sign)
{
    std::string str;
    float   n;

    if (*it == '-')
    {
        str += '-';
        it += 2;
    }
    for (;isdigit(*it) || *it == '.'; it++)
        str += *it;
    n = atof(str.c_str());
    if (sign == true)
        n *= -1;
    str = this->find_degree(it);
    setnbr(str, n);
    return it;
}

v1::~v1()
{
}
