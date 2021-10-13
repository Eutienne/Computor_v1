/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.cpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:15:25 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/13 18:19:56 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/v1.hpp"

v1::v1()
{
}

v1::v1(std::string str)
    : _mStr(str)
{
    _mForm.A =0; _mForm.B =0; _mForm.C =0; _mForm.D =0; _mForm.Degree =0; _mForm.solution1 =0; _mForm.solution2 =0; 
     
    this->find_token(_mStr);
}

v1::v1(v1 const & other)
{
    *this = other;
}

v1 v1::operator=(v1 const & other)
{
    _mStr = other._mStr;
    _mForm.Degree = other._mForm.Degree;
    _mForm.A = other._mForm.A;
    _mForm.B = other._mForm.B;
    _mForm.C = other._mForm.C;
    _mForm.D = other._mForm.D;
    _mForm.solution1 = other._mForm.solution1;
    _mForm.solution2 = other._mForm.solution2;
    return *this;
}

// float    v1::square_root()
// {
//     float i = 0.0;

//     for (; i*i < _mForm.D; i = i + 0.000001);

//     return (i);
// }

// long double    v1::square_root(long double d)
// {
//     long double i = 0.0;
//     for (; i*i <= d; i++){
//         if (i*i == d)
//             return i;
//     }

//     for (long double j = i + 0.1;i*i > d && i != j; j = i, i = i - 0.1);
//     for (long double j = i - 0.01; i*i < d && i != j; j = i, i = i + 0.01);
//     for (long double j = i + 0.001; i*i > d && i != j; j = i, i = i - 0.001);
//     for (long double j = i - 0.0001; i*i < d && i != j; j = i, i = i + 0.0001);
//     for (long double j = i + 0.00001; i*i > d && i != j; j = i, i = i - 0.00001);
//     for (long double j = i - 0.000001; i*i < d && i != j; j = i, i = i + 0.000001);
//     for (long double j = i + 0.0000001; i*i > d && i != j; j = i, i = i - 0.0000001);
//     for (long double j = i - 0.00000001; i*i < d && i != j; j = i, i = i + 0.00000001);
//     for (long double j = i + 0.000000001; i*i > d && i != j; j = i, i = i - 0.000000001);
//     for (long double j = i - 0.0000000001; i*i < d && i != j; j = i, i = i + 0.0000000001);
//     for (long double j = i + 0.00000000001; i*i > d && i != j; j = i, i = i - 0.00000000001);
 
//     return (i);
// }

void    v1::print2()
{
    if (_mForm.D > 0)
            std::cout << "Discriminant is strictly positive, the two solutions are:\n"
                << get_solution1() << std::endl
                << get_solution2() << std::endl;
        else if (_mForm.D >= 0)
            std::cout << "The solution is:\n" << get_solution1() << std::endl;
    else
        std::cout << "There is no solution" << std::endl;
}


void    v1::print()
{
    this->reduceform();
    std::cout << "Polynomial degree: " << get_Degree() << std::endl;

    switch (get_Degree())
    {
    case 0:
        std::cout << "The degree of zero polynomial is undefined" << std::endl;
        break;
    case 1:
        std::cout << "The solution is: " << get_solution1() << std::endl;
        break;
    case 2:
        print2();
        break;
    default:
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
        break;
    }
}

// void    v1::print_reduce_degree()
// {
//     this->reduceform();
//     std::cout << "Polynomial degree: " << _mForm.Degree << std::endl;
//     if (_mForm.Degree == 0)
//         std::cout << "The degree of zero polynomial is undefined" << std::endl;
//     else if (_mForm.Degree > 2)
//         std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
// }

// void    v1::solution()
// {
//     float   sqr;
//     if (_mForm.Degree == 1)
//         std::cout << "The solution is: " << _mForm.C / (_mForm.B * -1) << std::endl;
//     else
//     {
//         _mForm.D = (_mForm.B * _mForm.B) - 4 * _mForm.A * _mForm.C; 
        
//         sqr = this->square_root();
//         if (_mForm.D > 0)
//             std::cout << "Discriminant is strictly positive, the two solutions are:\n"
//                 << ((-_mForm.B) - sqr) / (2 * _mForm.A) << std::endl
//                 << ((-_mForm.B) + sqr) / (2 * _mForm.A) << std::endl;
//         else if (_mForm.D >= 0)
//             std::cout << "The solution is:\n" << ((-_mForm.B) + sqr) / (2 * _mForm.A) << std::endl;
//     else
//         std::cout << "There is no solution" << std::endl;
//     }
// }


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

float&   v1::get_A(){
    return (_mForm.A);
}

float&   v1::get_B(){
    return (_mForm.B);
}

float&   v1::get_C(){
    return (_mForm.C);
}

long double&   v1::get_D(){
    return (_mForm.D);
}

int     v1::get_Degree(){
    return (_mForm.Degree);
}

float& v1::get_solution1()
{
    return (_mForm.solution1);
}

float& v1::get_solution2()
{
    return (_mForm.solution2);
}


void    v1::setD()
{
    _mForm.D = (_mForm.B * _mForm.B) - 4 * _mForm.A * _mForm.C;
}

void    v1::setSolution1(float f)
{
    _mForm.solution1 = f;
}

void    v1::setSolution2(float f)
{
    _mForm.solution2 = f;
}

void    v1::setSolution()
{
    setSolution1 ((_mForm.C / (_mForm.B * -1)));
}

void    v1::setSolution(float f)
{
    setSolution1(((-_mForm.B) - f) / (2 * _mForm.A));
    if (f > 0)
        setSolution2(((-_mForm.B) + f) / (2 * _mForm.A));   
}


v1::~v1()
{
}
