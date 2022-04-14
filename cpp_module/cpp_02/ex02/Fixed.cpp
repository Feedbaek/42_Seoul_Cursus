/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 20:07:13 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 21:54:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//	멤버변수 fixed_point 반환함
int		Fixed::getRawBits(void) const {
	return (this->fixed_point);
}
//	멤버변수 fixed_point 설정함
void	Fixed::setRawBits(int const raw) {
	this->fixed_point = raw;
}
//	기본 생성자로 fixed_point 초기화
Fixed::Fixed() {
	this->fixed_point = 0;
}
//	int형 생성자
Fixed::Fixed(const int value) {
	this->fixed_point = value << this->fractional_bits;
}
//	float형 생성자
Fixed::Fixed(const float value) {
	this->fixed_point = roundf(value * (1 << this->fractional_bits));
}
//	소멸자
Fixed::~Fixed() {
}
//	복사 생성자
Fixed::Fixed(const Fixed &a) {
	*this = a;	// 오버로드 된 복사 대입 연산자로 작동함
}
//	복사 대입 연산자 오버로딩
Fixed	&Fixed::operator= (const Fixed &a) {
	this->fixed_point = a.fixed_point;
	return (*this);
}
//	연산자들 오버로딩
bool	Fixed::operator> (const Fixed &a) const {
	return (this->fixed_point > a.fixed_point);
}
bool	Fixed::operator< (const Fixed &a) const {
	return (this->fixed_point < a.fixed_point);
}
bool	Fixed::operator>= (const Fixed &a) const {
	return (this->fixed_point >= a.fixed_point);
}
bool	Fixed::operator<= (const Fixed &a) const {
	return (this->fixed_point >= a.fixed_point);
}
bool	Fixed::operator== (const Fixed &a) const {
	return (this->fixed_point == a.fixed_point);
}
bool	Fixed::operator!= (const Fixed &a) const {
	return (this->fixed_point != a.fixed_point);
}
Fixed	Fixed::operator+ (const Fixed &a) {
	return (Fixed(this->toFloat() + a.toFloat()));
}
Fixed	Fixed::operator- (const Fixed &a) {
	return (Fixed(this->toFloat() - a.toFloat()));
}
Fixed	Fixed::operator* (const Fixed &a) {
	return (Fixed(this->toFloat() * a.toFloat()));
}
Fixed	Fixed::operator/ (const Fixed &a) {
	return (Fixed(this->toFloat() / a.toFloat()));
}
Fixed	&Fixed::operator++ (void) {
	this->fixed_point++;
	return (*this);
}
Fixed	Fixed::operator++ (int) {
	Fixed tmp(*this);

	this->fixed_point++;
	return (tmp);
}
Fixed	&Fixed::operator-- (void) {
	this->fixed_point--;
	return (*this);
}
Fixed	Fixed::operator-- (int) {
	Fixed tmp(*this);

	this->fixed_point--;
	return (tmp);
}
//	고정 소수점 값을 실수형으로 바꿔서 반환
float	Fixed::toFloat(void) const {
	return ((float)this->fixed_point / (1 << this->fractional_bits));
}
//	고정 소수점 값을 정수형으로 바꿔서 반환
int		Fixed::toInt(void) const {
	return (this->fixed_point >> this->fractional_bits);
}
Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}
const Fixed	&Fixed::min(const Fixed &a, const Fixed &b) {
	if (a < b)
		return (a);
	return (b);
}
Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}
const Fixed	&Fixed::max(const Fixed &a, const Fixed &b) {
	if (a > b)
		return (a);
	return (b);
}
//	왼쪽 비트이동 연산자 오버로딩 함수
std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return (out);
}
