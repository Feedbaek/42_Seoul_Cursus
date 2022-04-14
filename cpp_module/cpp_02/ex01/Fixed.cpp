/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:35:44 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/13 22:45:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
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
	this->fixed_point = value;
}
Fixed::Fixed(const float value) {
	this->fixed_point = value;
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

float	Fixed::toFloat(void) {
	//return ((float)this->value)
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
