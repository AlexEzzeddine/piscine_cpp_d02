/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzeddi <aezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:04:29 by aezzeddi          #+#    #+#             */
/*   Updated: 2018/01/10 21:05:47 by aezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << this->nbits;
}

Fixed::Fixed(float const f)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(f * (1 << this->nbits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void Fixed::operator=(Fixed const& obj)
{
	std::cout << "Assignation operator called" << std::endl;
	value = obj.getRawBits();
}

std::ostream& operator<<(std::ostream& os, Fixed const& fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const
{
	return this->value / (float)(1 << this->nbits);
}

int Fixed::toInt(void) const
{
	return this->value / (1 << this->nbits);
}
