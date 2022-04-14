/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:31:26 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 20:21:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	멤버변수 fixed_point 반환함
int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->fixed_point);
}
//	멤버변수 fixed_point 설정함
void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->fixed_point = raw;
}
//	기본 생성자로 fixed_point 초기화
Fixed::Fixed() {
	std::cout << "Default constructor called\n";
	this->fixed_point = 0;
}
//	소멸자
Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}
//	복사 생성자
Fixed::Fixed(const Fixed &a) {
	std::cout << "Copy constructor called\n";
	*this = a;	// 오버로드 된 복사 대입 연산자로 작동함
}
//	복사 대입 연산자 오버로딩
Fixed	&Fixed::operator=(const Fixed &a) {
	std::cout << "Copy assignment operator called\n";
	this->fixed_point = a.getRawBits();
	return (*this);
}
