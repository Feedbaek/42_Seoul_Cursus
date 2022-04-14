/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:35:44 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 17:53:48 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		Fixed::getRawBits(void) const {
	return (this->fixed_point);
}
void	Fixed::setRawBits(const int raw) {
	this->fixed_point = raw;
}
Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->fixed_point = 0;
}
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	this->fixed_point = value << this->fractional_bits;
}
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	this->fixed_point = roundf(value * (1 << this->fractional_bits));
}
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
Fixed::Fixed(const Fixed &a) {
	std::cout << "Copy constructor called\n";
	*this = a;
}
Fixed	&Fixed::operator=(const Fixed &a) {
	std::cout << "Copy assignment operator called\n";
	this->fixed_point = a.getRawBits();
	return (*this);
}

float	Fixed::toFloat(void) const {
	return ((float)this->fixed_point / (1 << this->fractional_bits));
}

int		Fixed::toInt(void) const {
	return (this->fixed_point >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
