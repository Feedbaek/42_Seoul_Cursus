/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:49:53 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/17 21:28:41 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class Span {
private:
	std::vector<int> _vec;

public:
	class CannotStoreException : public std::exception {
		public:
			const char*	what() const throw();
	};
	class CannotSpanException : public std::exception {
		public:
			const char*	what() const throw();
	};
	Span();
	Span(std::size_t n);
	Span(const Span& a);
	~Span();

	Span&	operator=(const Span& a);

	void	addNumber(int value);

	template<typename T>
	void	addRange(T begin, T end) {
		if (std::distance(begin, end) > static_cast<int>(this->_vec.capacity() - this->_vec.size()))
			throw Span::CannotStoreException();
		while (begin != end) {
			this->_vec.push_back(*begin);
			begin++;
		}
	}

	std::size_t	shortestSpan();
	std::size_t	longestSpan();
};

#endif
