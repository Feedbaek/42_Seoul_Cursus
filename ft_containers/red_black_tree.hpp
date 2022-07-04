/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:13:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/04 20:47:47 by minskim2         ###   ########.fr       */
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
	node_pointer _root;
	node_pointer _node;
	node_pointer _end;

	node_pointer min_node(node_pointer node) {
		if (node == 0)
			return 0;
		while (node->left != 0)
			node = node->left;
		return node;
	}
	node_pointer max_node(node_pointer node) {
		if (node == 0)
			return 0;
		while (node->right != 0)
			node = node->right;
		return node;
	}

public:
	tree_iterator() : _root(0), _node(0), _end(0) {}
	tree_iterator(const tree_iterator& a) : _root(a._root), _node(a._node), _node(a._end) {}
	//tree_iterator(node_pointer a) : _node(a) {}

	virtual ~tree_iterator() {}

	tree_iterator& operator=(const tree_iterator& a) {
		if (this == &a)
			return *this;
		_root = a._root;
		_node = a._node;
		_end = a._end;
		return *this;
	}

	//node_pointer base() const {
	//	return _node;
	//}

	tree_iterator& operator++() {
		if (_node->right != 0) {
			_node = min_node(_node->right);
			return *this;
		}
		while (_node->parent != 0 && _node != _node->parent->left)
			_node = _node->parent;
		if (_node->parent != 0)
			_node = _node->parent;
		else
			_node = _end;
		return *this;
	}
	tree_iterator operator++(int) {
		tree_iterator tmp = *this;
		++(*this);
		return tmp;
	}
	tree_iterator& operator--() {
		if (_node->left != 0) {
			_node = max_node(_node->left);
			return *this;
		}
		while (_node->parent != 0 && _node != _node->parent->right)
			_node = _node->parent;
		if (_node->parent != 0)
			_node = _node->parent;
		else
			_node = _end;
		return *this;
	}
	tree_iterator operator--(int) {
		tree_iterator tmp = *this;
		--(*this);
		return tmp;
	}
	reference operator*() const {
		return _node->value;
	}
	pointer operator->() const {
		return &(_node->value);
	}
};

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
};

}

#endif
