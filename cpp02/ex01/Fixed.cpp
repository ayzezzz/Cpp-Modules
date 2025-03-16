/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:14:42 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 16:18:52 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue){
    std::cout << "Int constructor called" << std::endl;
    _fixedPoint = intValue << _fixedPointBits;
}

Fixed::Fixed(const float floatValue){
    std::cout << "Float constructor called" << std::endl;
    _fixedPoint = roundf(floatValue * (1 << _fixedPointBits));
}

Fixed::Fixed(const Fixed &other): _fixedPoint(other._fixedPoint){
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        _fixedPoint = other._fixedPoint;
    }
    return *this;
}
int Fixed::getRawBits(void) const{
    return _fixedPoint;
}

void Fixed::setRawBits(int const raw){
    _fixedPoint = raw;
}

int Fixed::toInt(void) const{
    return _fixedPoint >> _fixedPointBits;
}
float Fixed::toFloat(void) const{
    return (float)_fixedPoint / (1 << _fixedPointBits);
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed){
    os << fixed.toFloat();
    return os;
}
Fixed::~Fixed(){
    std::cout << "Destructor called" << std::endl;
}