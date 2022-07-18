/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:57:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/18 20:58:27 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

template<typename T, typename Container = vector<T> >
class stack {
public:
	typedef T			value_type;
	typedef Container	container_type;
	typedef size_t		size_type;

protected:
	container_type c;

public:
	explicit stack(const container_type& ctnr = container_type()) {
		c = ctnr;
	}

	bool empty() const {
		return c.empty();
	}
	size_type size() const {
		return c.size();
	}
	value_type& top() {
		return c.back();
	}
	const value_type& top() const {
		return c.back();
	}
	void push(const value_type& val) {
		c.push_back(val);
	}
	void pop() {
		c.pop_back();
	}

protected:
	template<typename C, typename U>
	friend bool operator==(const stack<C,U>&lhs, const stack<C, U>& rhs);
	template<typename C, typename U>
	friend bool operator<(const stack<C,U>&lhs, const stack<C, U>& rhs);
};

template <class T, class Container>
bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.c == rhs.c;
}
template <class T, class Container>
bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return !(lhs == rhs);
}
template <class T, class Container>
bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return lhs.c < rhs.c;
}
template <class T, class Container>
bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return !(rhs < lhs);
}
template <class T, class Container>
bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return rhs < lhs;
}
template <class T, class Container>
bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
	return !(lhs < rhs);
}

}

#endif
