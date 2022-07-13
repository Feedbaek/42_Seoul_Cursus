/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:29:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/13 21:44:11 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "iterator.hpp"

namespace ft {

template<typename InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
	typename iterator_traits<InputIterator>::difference_type diff = 0;
	typename iterator_traits<InputIterator>::difference_type sign = 1;
	if (first > last) {
		InputIterator tmp = first;
		first = last;
		last = tmp;
		sign = -1;
	}
	for (;first != last; first++, diff++) {	}
	return sign * diff;
}

enum Color {
	RED,
	BLACK,
	DBLACK
};

template<typename T>
struct tree_node {
	typedef T		value_type;
	typedef Color	color_type;

	value_type		value;
	tree_node*		parent;
	tree_node*		left;
	tree_node*		right;
	color_type		color;

	tree_node() : value(), parent(0), left(0), right(0), color(RED) {
	}
	tree_node(const value_type& val, tree_node* pr = 0, tree_node* lf = 0, tree_node* ri = 0, color_type col = RED)
		: value(val), parent(pr), left(lf), right(ri), color(col) {
	}
	tree_node(const tree_node& a) : value(a.value), parent(a.parent), left(a.left), right(a.right), color(a.color) {
	}

	virtual ~tree_node() {}

	tree_node& operator=(const tree_node& a) {
		if (this == &a)
			return (*this);
		value = a.value;
		parent = a.parent;
		left = a.left;
		right = a.right;
		color = a.color;
		return (*this);
	}
	bool operator==(const tree_node& other) {
		if (value == other.value)
			return true;
		return false;
	}
	bool operator!=(const tree_node& other) {
		if (value != other.value)
			return true;
		return false;
	}
};

template<typename T1, typename T2>
bool operator==(const tree_node<T1>& lhs, const tree_node<T2>& rhs) {
	if (lhs.value == rhs.value)
		return true;
	return false;
}
template<typename T1, typename T2>
bool operator!=(const tree_node<T1>& lhs, const tree_node<T2>& rhs) {
	if (lhs.value != rhs.value)
		return true;
	return false;
}

}

#endif
