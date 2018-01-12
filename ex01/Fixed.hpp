/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzeddi <aezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:04:46 by aezzeddi          #+#    #+#             */
/*   Updated: 2018/01/10 21:09:06 by aezzeddi         ###   ########.fr       */
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

		void operator=(Fixed const& obj);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

	private:
		int value;
		
		static int const nbits = 8;
};
		
std::ostream& operator<<(std::ostream& os, Fixed const& fixed);

#endif