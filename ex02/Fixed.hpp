/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzeddi <aezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:04:46 by aezzeddi          #+#    #+#             */
/*   Updated: 2018/01/10 23:23:47 by aezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& obj);
		Fixed(int const n);
		Fixed(float const f);
		~Fixed();

		Fixed& operator=(Fixed const& obj);
		bool operator>(Fixed const& obj);
		bool operator<(Fixed const& obj);
		bool operator>=(Fixed const& obj);
		bool operator<=(Fixed const& obj);
		bool operator==(Fixed const& obj);
		bool operator!=(Fixed const& obj);

		Fixed operator+(Fixed const& obj);
		Fixed operator-(Fixed const& obj);
		Fixed operator*(Fixed const& obj);
		Fixed operator/(Fixed const& obj);

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		static Fixed min(Fixed const& obj1, Fixed const& obj2);
		static Fixed max(Fixed const& obj1, Fixed const& obj2);
	private:
		int value;

		static int const nbits = 8;
};
		
std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif