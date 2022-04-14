/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:06:59 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 21:37:17 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int	fixed_point;
	static const int fractional_bits = 8;
public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &a);
	Fixed	&operator= (const Fixed &a);
	~Fixed();

	bool	operator> (const Fixed &a) const;
	bool	operator< (const Fixed &a) const;
	bool	operator>= (const Fixed &a) const;
	bool	operator<= (const Fixed &a) const;
	bool	operator== (const Fixed &a) const;
	bool	operator!= (const Fixed &a) const;

	Fixed	operator+ (const Fixed &a);
	Fixed	operator- (const Fixed &a);
	Fixed	operator* (const Fixed &a);
	Fixed	operator/ (const Fixed &a);

	Fixed	&operator++ (void);
	Fixed	operator++ (int);
	Fixed	&operator-- (void);
	Fixed	operator-- (int);

	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	float	toFloat(void) const;
	int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
