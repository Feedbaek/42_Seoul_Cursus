/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:40:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/08 00:02:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _e(false), _input(""), _value(0.0) {
}

Convert::Convert(const std::string input) : _e(false), _input(input), _value(0.0) {
	try {
		char *ptr = NULL;
		*(const_cast<double*>(&(this->_value))) = std::strtod(this->_input.c_str(), &ptr);
		//if (this->_value == 0.0 )
	} catch (std::exception &e) {
		this->_e = true;
	}
}
Convert::Convert(const Convert &a) : _e(false), _input(a._input), _value(a._value) {
}
Convert::~Convert() {
}

Convert	&Convert::operator=(const Convert &a) {
	this->_e = a._e;
	*(const_cast<std::string*>(&(this->_input))) = a._input;
	*(const_cast<double*>(&(this->_value))) = a._value;
	return *this;
}

char	Convert::toChar() const {
	return static_cast<char>(this->_value);
}
int		Convert::toInt() const {
	return static_cast<int>(this->_value);
}
float	Convert::toFloat() const {
	return static_cast<float>(this->_value);
}
double	Convert::toDouble() const {
	return static_cast<double>(this->_value);
}

bool	Convert::getError() const {
	return this->_e;
}
double	Convert::getValue() const {
	return this->_value;
}
std::string	Convert::getInput() const {
	return this->_input;
}
