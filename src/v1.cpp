/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   v1.cpp                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: eutrodri <eutrodri@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/10 23:15:25 by eutrodri      #+#    #+#                 */
/*   Updated: 2021/10/20 20:02:42 by eutrodri      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/v1.hpp"

long double    square_root(long double d)
{
    long double i = 0.0;
    for (; i*i <= d; i++){
        if (i*i == d)
            return i;
    }

    for (long double j = i + 0.1;i*i > d && i != j; j = i, i = i - 0.1);
    for (long double j = i - 0.01; i*i < d && i != j; j = i, i = i + 0.01);
    for (long double j = i + 0.001; i*i > d && i != j; j = i, i = i - 0.001);
    for (long double j = i - 0.0001; i*i < d && i != j; j = i, i = i + 0.0001);
    for (long double j = i + 0.00001; i*i > d && i != j; j = i, i = i - 0.00001);
    for (long double j = i - 0.000001; i*i < d && i != j; j = i, i = i + 0.000001);
    for (long double j = i + 0.0000001; i*i > d && i != j; j = i, i = i - 0.0000001);
    for (long double j = i - 0.00000001; i*i < d && i != j; j = i, i = i + 0.00000001);
    for (long double j = i + 0.000000001; i*i > d && i != j; j = i, i = i - 0.000000001);
    for (long double j = i - 0.0000000001; i*i < d && i != j; j = i, i = i + 0.0000000001);
    for (long double j = i + 0.00000000001; i*i > d && i != j; j = i, i = i - 0.00000000001);
 
    return (i);
}


v1::v1()
{
}

v1::v1(std::string str)
    : _mStr(str)
{
    _mForm.A =0; _mForm.B =0; _mForm.C =0; _mForm.D =0; _mForm.Degree =0; _mForm.solution1 =0; _mForm.solution2 =0; 
    try
    {
        this->find_token(_mStr);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        exit(-1);
    } 
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

void    v1::print2()
{
    if (_mForm.D > 0)
            std::cout << "Discriminant is strictly positive, the two solutions are:\n"
                << getSolution1() << std::endl
                << getSolution2() << std::endl;
        else if (_mForm.D >= 0)
            std::cout << "The solution is:\n" << getSolution1() << std::endl;
    else
        std::cout << "There is no solution" << std::endl;
}


void    v1::print()
{
    this->reduceform();
    std::cout << "Polynomial degree: " << getDegree() << std::endl;

    if (_mForm.A == 0 && _mForm.B == 0 && _mForm.C == 0 && getDegree() < 3)
    {
        std::cout << "Every real number is a solution" << std::endl;
        return ; 
    }

    switch (getDegree())
    {
    case 0:
        std::cout << "The degree of zero polynomial is undefined" << std::endl;
        break;
    case 1:
        std::cout << "The solution is: \n" << getSolution1() << std::endl;
        break;
    case 2:
        print2();
        break;
    default:
        std::cout << "The polynomial degree is strictly greater than 2, I can't solve." << std::endl;
        break;
    }
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
        std::cout << atoi(_mReduce[i].second.c_str()) << " ";
    }
    std::cout << "= 0\"" << std::endl;
}

std::string    v1::find_degree(std::string::const_iterator & it)
{
    std::string str;
    for (int i = 0; *it == ' ' || *it == '*'; it++)
    {
        if (*it == '*')
            i++;
        if (i > 1)
            throw std::runtime_error("ERROR: to mutch '*' sign");
    }
    if (*it == 'x' || *it == 'X')
    {
        it++;
        if (*it && *it == '^')
        {
            it++;
            if (*it == '-')
                throw std::runtime_error("ERROR: Cant have a negative power!");
            else if (*it == '.')
                throw std::runtime_error("ERROR: Cant have a float as power!");
            for (;isdigit(*it); it++)
                str += *it;
        }
        else if ((!*it) || *it == ' ')
            str = "1";
        else
            throw std::runtime_error("ERROR: Wrong Format");
    }
    else
        return "0";
    return str;
}

void    v1::setnbr(std::string const &str, float n)
{
    for (size_t i = 0; i < _mReduce.size(); i++)
    {
        if (atoi(_mReduce[i].second.c_str()) == atoi(str.c_str()))
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
        if (!*it)
            return ;
        if (*it == '=' && sign == false)
            sign = true;
        else if (*it == '=' && sign == true)
            throw std::runtime_error("ERROR: can't have 2 times a '=' sign ");
        if (isdigit(*it) || *it == '-' || *it == 'x' || *it == 'X')
            it = store_diget(it, sign);
        else if (!(*it == ' ' || *it == '+' || *it == '='))
            throw std::runtime_error("ERROR: Wrong Format");

    }
}

std::string::const_iterator v1::store_diget(std::string::const_iterator it, bool sign)
{
    std::string str;
    float   n;

    if (*it == '-')
    {
        str += '-';
        for (; !isdigit(*it); it++);
    }
    if (*it == 'x' || *it == 'X')
        str =+ '1';
    for (;isdigit(*it) || *it == '.'; it++)
        str += *it;
    n = atof(str.c_str());
    if (sign == true)
        n *= -1;
    str = this->find_degree(it);
    if (n != 0)
    {
        if (atof(str.c_str()) > _mForm.Degree)
            _mForm.Degree = atof(str.c_str());
        setnbr(str, n);
    }
    return --it;
}

float&   v1::getA(){
    return (_mForm.A);
}

float&   v1::getB(){
    return (_mForm.B);
}

float&   v1::getC(){
    return (_mForm.C);
}

long double&   v1::getD(){
    return (_mForm.D);
}

int     v1::getDegree(){
    return (_mForm.Degree);
}

float& v1::getSolution1()
{
    return (_mForm.solution1);
}

float& v1::getSolution2()
{
    return (_mForm.solution2);
}


void    v1::setD()
{
    _mForm.D = (_mForm.B * _mForm.B) - 4 * _mForm.A * _mForm.C;
}

void    v1::setSolution1(float f)
{
    _mForm.solution1 = f == 0? 0 : f;
}

void    v1::setSolution2(float f)
{
    _mForm.solution2 = f == 0? 0 : f;
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
