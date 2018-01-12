/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzeddi <aezzeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 20:04:46 by aezzeddi          #+#    #+#             */
/*   Updated: 2018/01/10 20:59:43 by aezzeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& obj);
		~Fixed();

		void operator = (Fixed const& obj);
		int getRawBits( void ) const;
		void setRawBits( int const raw ); 

	private:
		int value;
		
		static int const nbits = 8;
};

#endif