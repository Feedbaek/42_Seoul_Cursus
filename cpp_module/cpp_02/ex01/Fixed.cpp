/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:35:44 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 20:48:59 by minskim2         ###   ########.fr       */
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
//	int형 생성자
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called\n";
	this->fixed_point = value << this->fractional_bits;
}
//	float형 생성자
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called\n";
	this->fixed_point = roundf(value * (1 << this->fractional_bits));
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
	this->fixed_point = a.fixed_point;
	return (*this);
}
//	고정 소수점 값을 실수형으로 바꿔서 반환
float	Fixed::toFloat(void) const {
	return ((float)this->fixed_point / (1 << this->fractional_bits));
}
//	고정 소수점 값을 정수형으로 바꿔서 반환
int		Fixed::toInt(void) const {
	return (this->fixed_point >> this->fractional_bits);
}
//	왼쪽 비트이동 연산자 오버로딩 함수
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
