/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:26:47 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/18 17:55:52 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
# define MUTANT_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack: public std::stack<T> {
private:

public:
	MutantStack() {
	}
	MutantStack(const MutantStack& a) {
		*this = a;
	}
	~MutantStack() {
	}

	MutantStack&	operator=(const MutantStack& a) {
		if (this != &a)
			std::stack<T>::operator=(a);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator	begin() {
		return this->c.begin();
	}
	iterator	end() {
		return this->c.end();
	}
	reverse_iterator	rbegin() {
		return this->c.rbegin();
	}
	reverse_iterator	rend() {
		return this->c.rend();
	}
	const_iterator	cbegin() {
		return this->c.cbegin();
	}
	const_iterator	cend() {
		return this->c.cend();
	}
	const_reverse_iterator	crbegin() {
		return this->c.crbegin();
	}
	const_reverse_iterator	crend() {
		return this->c.crend();
	}
};

#endif
