/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:37:12 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/15 22:46:49 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char*	Span::CannotStoreException::what() const throw() {
	return "Max size";
}
const char*	Span::CannotSpanException::what() const throw() {
	return "One element";
}

Span::Span() {
	this->_vec.reserve(0);
}
Span::Span(std::size_t n) {
	this->_vec.reserve(n);
}
Span::Span(const Span& a) {

}
Span::~Span() {

}

void	Span::addNumber(int value) {
	if (this->_vec.size() == this->_vec.capacity())
		throw Span::CannotSpanException();
	this->_vec.push_back(value);
}
