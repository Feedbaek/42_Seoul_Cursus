/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:31:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/13 11:33:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point);
}
void	Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
}
Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->fixed_point = 0;
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
