/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 22:37:12 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/17 21:40:40 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char*	Span::CannotStoreException::what() const throw() {
	return "Not Enough Capacity";
}
const char*	Span::CannotSpanException::what() const throw() {
	return "Not Enough Element";
}

Span::Span() {
	this->_vec.reserve(0);
}
Span::Span(std::size_t n) {
	this->_vec.reserve(n);
}
Span::Span(const Span& a) {
	this->_vec.reserve(a._vec.capacity());
	std::copy(a._vec.begin(), a._vec.end(), std::back_inserter(this->_vec));
}
Span::~Span() {
}

Span&	Span::operator=(const Span& a) {
	if (this->_vec.capacity() < a._vec.capacity())
		throw Span::CannotStoreException();
	if (this != &a) {
		this->_vec.clear();
		std::copy(a._vec.begin(), a._vec.end(), std::back_inserter(this->_vec));
	}
	return *this;
}

void	Span::addNumber(int value) {
	if (this->_vec.size() == this->_vec.capacity())
		throw Span::CannotStoreException();
	this->_vec.push_back(value);
}

std::size_t	Span::shortestSpan() {
	if (this->_vec.size() < 2)
		throw Span::CannotSpanException();
	std::vector<int> tmp(this->_vec);
	int min = *(tmp.end()-=1) - *(tmp.begin());
	std::sort(tmp.begin(), tmp.end());
	for (std::size_t i=0; i+1<tmp.size(); i++) {
		if (tmp[i+1] - tmp[i] < min)
			min = tmp[i+1] - tmp[i];
	}
	return min;
}

std::size_t	Span::longestSpan() {
	if (this->_vec.size() < 2)
		throw Span::CannotSpanException();
	std::vector<int> tmp(this->_vec);
	std::sort(tmp.begin(), tmp.end());
	return *(tmp.end()-=1) - *(tmp.begin());
}
