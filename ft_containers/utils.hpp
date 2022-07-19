/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:29:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/19 20:25:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "iterator.hpp"

namespace ft {

template < typename InputIt >
typename ft::iterator_traits<InputIt>::difference_type	distance(InputIt first, InputIt last) {
	typename ft::iterator_traits<InputIt>::difference_type	dist = 0;
	while (first != last){
		++first;
		++dist;
	}
	return dist;
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
