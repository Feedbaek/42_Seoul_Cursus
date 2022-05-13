/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:40:17 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/09 22:06:35 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert() : _input("") {
}

Convert::Convert(const std::string input) : _input(input) {
}
Convert::Convert(const Convert &a) : _input(a._input) {
}
Convert::~Convert() {
}

Convert	&Convert::operator=(const Convert &a) {
	this->_input = a._input;
	return *this;
}

char	Convert::toChar() const {
	try {
		int tmp = std::stoi(this->_input);
		if (isprint(tmp))
			return static_cast<char>(tmp);
		else if (tmp > 255 || tmp < 0)
			throw Convert::ImpossibleException();
		else
			throw Convert::NonDisplayableException();
	} catch (std::exception &e) {
		throw Convert::ImpossibleException();
	}
}
int		Convert::toInt() const {
	try {
		int tmp = std::stoi(this->_input);
		return tmp;
	} catch (std::exception &e) {
		throw Convert::ImpossibleException();
	}
}
float	Convert::toFloat() const {
	try {
		float tmp = std::stof(this->_input);
		return tmp;
	} catch (std::exception &e) {
		throw Convert::ImpossibleException();
	}
}
double	Convert::toDouble() const {
	try {
		float tmp = std::stod(this->_input);
		return tmp;
	} catch (std::exception &e) {
		throw Convert::ImpossibleException();
	}
}

std::string	Convert::getInput() const {
	return this->_input;
}

const char* Convert::ImpossibleException::what() const throw() {
	return ("impossible");
}

const char* Convert::NonDisplayableException::what() const throw() {
	return ("Non displayable");
}
