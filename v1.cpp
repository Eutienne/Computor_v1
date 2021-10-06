/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.cpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:15:25 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/06 13:07:50 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "v1.hpp"

v1::v1()
{
}

v1::v1(std::string str)
    : _mStr(str)
{
    _mForm.A =0; _mForm.B =0; _mForm.C =0; _mForm.D =0; _mForm.Degree =0; 
     
    this->find_token(_mStr);
    this->print();
    if (_mForm.Degree < 3 && _mForm.Degree > 0)
        this->solution();
    else if (_mForm.Degree == 0)
        std::cout << "The degree of zero polynomial is undefined" << std::endl;
    else
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
}

v1::v1(v1 const & other)
{
    *this = other;
}

v1 v1::operator=(v1 const & other)
{
    _mStr = other._mStr;
    _mForm.Degree = other._mForm.Degree;
    return *this;
}

void    v1::square_root()
{
    float i = 0.000001;

    for (; i*i < _mForm.D; i = i + 0.000001);

    if (_mForm.D > 0)
        std::cout << "Discriminant is strictly positive, the two solutions are:\n"
        << ((-_mForm.B) - i) / (2 * _mForm.A) << std::endl
        << ((-_mForm.B) + i) / (2 * _mForm.A) << std::endl;
    else if (_mForm.D >= 0)
        std::cout << "The solution is:\n" << ((-_mForm.B) + i) / (2 * _mForm.A) << std::endl;
    else
        std::cout << "There is no solution" << std::endl;
}


void    v1::print()
{

    this->reduceform();
    std::cout << "Polynomial degree: " << _mForm.Degree << std::endl;
}

void    v1::solution()
{
    if (_mForm.Degree == 1)
        std::cout << "The solution is: " << _mForm.C / (_mForm.B * -1) << std::endl;
    else
        this->square_root();
}


void    v1::reduceform()
{
    std::cout << "Reduced form: \"";
    for (size_t i = 0; i < _mReduce.size(); i++)
    {
        if (i != 0 && _mReduce[i].first > 0)
            std::cout << "+ ";
        else if (i != 0 && _mReduce[i].first < 0)
        {
            std::cout << "- ";
            if (_mReduce[i].first != 0)
                _mReduce[i].first *= -1;
        }
        else if (i != 0 && _mReduce[i].first == 0)
        {
            if (1/(_mReduce[i].first) == 1/(-0.0))
            {
                std::cout << "- ";
                _mReduce[i].first *= -1;
            }
            else
                std::cout << "+ ";
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
    if (atof(str.c_str()) > _mForm.Degree)
        _mForm.Degree = atof(str.c_str());
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
        _mForm.C += n;
    else if (atof(str.c_str()) == 1)
        _mForm.B += n;
    else if (atof(str.c_str()) == 2)
        _mForm.A += n;
}


void    v1::find_token(std::string const & str)
{
    bool sign = false;
    for(std::string::const_iterator it = str.begin(); it != str.end(); it++)
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
    return --it;
}

v1::~v1()
{
}
