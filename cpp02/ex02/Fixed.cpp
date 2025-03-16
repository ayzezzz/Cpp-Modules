/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zayaz <zayaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 13:15:02 by zayaz             #+#    #+#             */
/*   Updated: 2025/03/16 14:08:26 by zayaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
Fixed::Fixed() : _fixedPoint(0) {}

Fixed::Fixed(const int intValue) {
    _fixedPoint = intValue << _fixedPointBits;
}

Fixed::Fixed(const float floatValue) {
    _fixedPoint = roundf(floatValue * (1 << _fixedPointBits));
}

Fixed::Fixed(const Fixed &other) : _fixedPoint(other._fixedPoint) {}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other) {
        _fixedPoint = other._fixedPoint;
    }
    return *this;
}
bool Fixed::operator>(const Fixed &other) const{
    return _fixedPoint > other._fixedPoint;
}

bool Fixed::operator<(const Fixed &other) const{
    return _fixedPoint < other._fixedPoint;
}

bool Fixed::operator>=(const Fixed &other) const{
    return _fixedPoint >= other._fixedPoint;
}

bool Fixed::operator<=(const Fixed &other) const{
    return _fixedPoint <= other._fixedPoint;
}

bool Fixed::operator==(const Fixed &other) const{
    return _fixedPoint == other._fixedPoint;
}

bool Fixed::operator!=(const Fixed &other) const{
    return _fixedPoint != other._fixedPoint;
}

Fixed Fixed::operator+(const Fixed &other) const{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const{
    return Fixed(this->toFloat() / other.toFloat());
}
Fixed &Fixed::operator++(){
    _fixedPoint++;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed temp(*this);
    _fixedPoint++;
    return temp;
}

Fixed &Fixed::operator--(){
    _fixedPoint--;
    return *this;
}

Fixed Fixed::operator--(int){
    Fixed temp(*this);
    _fixedPoint--;
    return temp;
}
Fixed &Fixed::min(Fixed &a, Fixed &b){
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    return (a > b) ? a : b;
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