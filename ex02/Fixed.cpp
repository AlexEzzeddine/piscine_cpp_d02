/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzeddi <aezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:04:29 by aezzeddi          #+#    #+#             */
/*   Updated: 2018/01/12 20:49:19 by aezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(): value(0)
{
	return;
}

Fixed::Fixed(Fixed const& obj)
{
	this->value = obj.getRawBits();
	return;
}

Fixed::Fixed(int const n)
{
	value = n * (1 << this->nbits);
	return;
}

Fixed::Fixed(float const f)
{
	value = roundf(f * (1 << this->nbits));
	return;
}

Fixed::~Fixed()
{
	return;
}

Fixed& Fixed::operator=(Fixed const& obj)
{
	this->value = obj.getRawBits();
	return *this;
}

bool Fixed::operator>(Fixed const& obj)
{
	return this->getRawBits() > obj.getRawBits();
}

bool Fixed::operator<(Fixed const& obj)
{
	return this->getRawBits() < obj.getRawBits();
}

bool Fixed::operator>=(Fixed const& obj)
{
	return this->getRawBits() >= obj.getRawBits();
}

bool Fixed::operator<=(Fixed const& obj)
{
	return this->getRawBits() <= obj.getRawBits();
}

bool Fixed::operator==(Fixed const& obj)
{
	return this->getRawBits() == obj.getRawBits();
}

bool Fixed::operator!=(Fixed const& obj)
{
	return this->getRawBits() != obj.getRawBits();
}

Fixed Fixed::operator+(Fixed const& obj)
{
	return Fixed(this->getRawBits() + obj.getRawBits());
}

Fixed Fixed::operator-(Fixed const& obj)
{
	return Fixed(this->getRawBits() - obj.getRawBits());
}

Fixed Fixed::operator*(Fixed const& obj)
{
	Fixed result;
	result.setRawBits(this->value * obj.getRawBits() / (1 << this->nbits));
	return result;
}

Fixed Fixed::operator/(Fixed const& obj)
{
	Fixed result;
	result.setRawBits(this->value / obj.getRawBits() * (1 << this->nbits));
	return result;
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return os;
}

Fixed & Fixed::operator++()
{
	++(this->value);
	return *this;
}

Fixed & Fixed::operator--()
{
	--(this->value);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return old;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	--(*this);
	return old;
}

int Fixed::getRawBits() const
{
	return value;
}

void Fixed::setRawBits(int const raw)
{
	value = raw;
}

float Fixed::toFloat(void) const
{
	return this->value / float(1 << this->nbits);
}

int Fixed::toInt(void) const
{
	return this->value / (1 << this->nbits);
}

Fixed const Fixed::min(Fixed const& obj1, Fixed const& obj2)
{
	return obj1.getRawBits() < obj2.getRawBits() ? obj1 : obj2;
}

Fixed const Fixed::max(Fixed const& obj1, Fixed const& obj2)
{
	return obj1.getRawBits() > obj2.getRawBits() ? obj1 : obj2;
}

Fixed Fixed::min(Fixed& obj1, Fixed& obj2)
{
	return obj1.getRawBits() < obj2.getRawBits() ? obj1 : obj2;
}

Fixed Fixed::max(Fixed& obj1, Fixed& obj2)
{
	return obj1.getRawBits() > obj2.getRawBits() ? obj1 : obj2;
}
