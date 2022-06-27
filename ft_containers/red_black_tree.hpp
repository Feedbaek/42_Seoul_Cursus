/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:13:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/27 22:20:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <memory>
# include <cstddef>

# include "iterator.hpp"
# include "utils.hpp"

namespace ft {

template<typename T>
class tree_iterator : public iterator<bidirectional_iterator_tag, T> {
public:
	typedef tree_node<T>	node;
	typedef tree_node<T>*	node_pointer;

	typedef bidirectional_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef value_type&					reference;
	typedef std::ptrdiff_t				difference_type;
	typedef T*							pointer;

private:
	node_pointer _node;

public:
	tree_iterator() : _node(0) {}
	tree_iterator(const tree_iterator& a) : _node(a._node) {}
	tree_iterator(node_pointer a) : _node(a) {}

	virtual ~tree_iterator() {}

	tree_iterator& operator=(const tree_iterator& a) {
		if (this == &a)
			return *this;
		_node = a._node;
		return *this;
	}
	tree_iterator& operator++() {
		if (_node->right != 0) {

		}
	}
}

template<typename T, typename Compare>
class red_black_tree {
public:
	typedef T							value_type;
	typedef Compare						value_compare;
	typedef std::allocator<T>			allocator_type;
	typedef size_t						size_type;
	typedef std::ptrdiff_t				difference_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;

	typedef red_black_tree				rbtree;
	typedef tree_node<T>				node_type;
	typedef tree_node<T>*				node_pointer;
	typedef std::allocator<node_type>	node_alloc_type;
}

}

#endif
