/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:13:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/05 21:21:53 by minskim2         ###   ########.fr       */
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
	node_pointer _cmd_node;		// left == root, right == end
	node_pointer _node;

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
	tree_iterator() : _cmd_node(0), _node(0) {}
	tree_iterator(const tree_iterator& a) : _cmd_node(a._cmd_node), _node(a._node) {}
	tree_iterator(const tree_const_iterator<T>& a) {
		_node = a.base();
		_cmd_node = a.cmd();
	}
	tree_iterator(node_pointer cmd, node_pointer node) : _cmd_node(cmd), _node(node) {}

	virtual ~tree_iterator() {}

	tree_iterator& operator=(const tree_iterator& a) {
		if (this == &a)
			return *this;
		_node = a._node;
		_cmd_node = a._cmd_node;
		return *this;
	}
	tree_iterator& operator=(const tree_const_iterato<T>& a) {
		if (this == &a)
			return *this;
		_node = a.base();
		_cmd_node = a.cmd()
		return *this;
	}

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
			_node = _cmd_node->right;
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
			_node = _cmd_node->right;
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
	bool operator==(const tree_iterator &a) {
		return _node == a.base();
	}
	bool operator==(const tree_const_iterator<T> &a) {
		return _node == a.base();
	}
	bool operator!=(const tree_iterator &a) {
		return _node != a.base();
	}
	bool operator!=(const tree_const_iterator<T> &a) {
		return _node != a.base();
	}

	node_pointer base() const {
		return _node;
	}
	node_pointer cmd() const {
		return _cmd_node;
	}
};

template<typename T>
class tree_const_iterator : public iterator<bidirectional_iterator_tag, T> {
public:
	typedef tree_node<T>				node;
	typedef tree_node<T>*				node_pointer;

	typedef bidirectional_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef const T&					reference;
	typedef std::ptrdiff_t				difference_type;
	typedef const T*					pointer;

private:
	node_pointer _node;
	node_pointer _cmd_node;

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
	tree_const_iterator() : _cmd_node(0), _node(0) {}
	tree_const_iterator(const tree_const_iterator& a) : _cmd_node(a._cmd_node), _node(a._node) {}
	tree_const_iterator(const tree_iterator& a) {
		_cmd_node = a.cmd();
		_node = a.node();
	}
	tree_const_iterator(node_pointer cmd, node_pointer node) : _cmd_node(cmd), _node(node) {}

	virtual ~tree_const_iterator() {}

	tree_const_iterator& operator=(const tree_const_iterator& a) {
		if (this == &a)
			return *this;
		_cmd_node = a._cmd_node;
		_node = a._node;
		return *this;
	}
	tree_const_iterator& operator=(const tree_iterator<T>& a) {
		if (this == &a)
			return *this;
		_cmd_node = a.cmd();
		_node = a._node;
		return *this;
	}

	tree_const_iterator& operator++() {
		if (_node->right != 0) {
			_node = min_node(_node->right);
			return *this;
		}
		while (_node->parent != 0 && _node != _node->parent->left)
			_node = _node->parent;
		if (_node->parent != 0)
			_node = _node->parent;
		else
			_node = _cmd_node->right;
		return *this;
	}
	tree_const_iterator operator++(int) {
		tree_const_iterator tmp = *this;
		++(*this);
		return tmp;
	}
	tree_const_iterator& operator--() {
		if (_node->left != 0) {
			_node = max_node(_node->left);
			return *this;
		}
		while (_node->parent != 0 && _node != _node->parent->right)
			_node = _node->parent;
		if (_node->parent != 0)
			_node = _node->parent;
		else
			_node = _cmd_node->right;
		return *this;
	}
	tree_const_iterator operator--(int) {
		tree_const_iterator tmp = *this;
		--(*this);
		return tmp;
	}
	reference operator*() const {
		return _node->value;
	}
	pointer operator->() const {
		return &(_node->value);
	}
	bool operator==(const tree_const_iterator &a) {
		return _node == a.base();
	}
	bool operator==(const tree_iterator<T> &a) {
		return _node == a.base();
	}
	bool operator!=(const tree_const_iterator &a) {
		return _node != a.base();
	}
	bool operator!=(const tree_iterator<T> &a) {
		return _node != a.base();
	}

	node_pointer cmd() const {
		return _cmd_node;
	}
	node_pointer base() const {
		return _node;
	}
};

template<typename T, typename Compare>
class red_black_tree {
public:
	typedef T											value_type;
	typedef Compare										value_compare;
	typedef std::allocator<T>							allocator_type;
	typedef size_t										size_type;
	typedef std::ptrdiff_t								difference_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef tree_iterator<T>							iterator;
	typedef tree_const_iterator<T>						const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	typedef red_black_tree								rbtree;
	typedef tree_node<T>								node_type;
	typedef tree_node<T>*								node_pointer;
	typedef std::allocator<node_type>					node_alloc_type;

private:
	value_compare _comp;
	allocator_type _alloc;
	node_alloc_type _node_alloc;
	node_pointer _cmd_node;  // left == root, right == end
	size_type _size;

public:
	red_black_tree() : _cmd_node(0), _size(0) {
		_cmd_node = _node_alloc.allocate(1);
		_node_alloc.construct(_cmd_node, node_type());
	}
	red_black_tree(const red_black_tree& a)
	  : _comp(a._comp), _alloc(a._alloc), _node_alloc(a._node_alloc), _cmd_node(0), _size(0) {
		_cmd_node = _node_alloc.allocate(1);
		_node_alloc.construct(_cmd_node, node_type());
		if (a.getRoot() != 0)
			copy_tree(a.getRoot());
	}

	virtual ~red_black_tree() {
		clear();
		_node_alloc.destroy(_cmd_node);
		_node_alloc.deallocate(_cmd_node, 1);
	}

	red_black_tree& operator=(const red_black_tree& a) {
		if (this == &a)
			return *this;
		clear();
		_comp = a._comp;
		_alloc = a._alloc;
		_node_alloc = a._node_alloc;
		copy_tree(a.getRoot());
		return *this;
	}

// Iterators:
	iterator begin() {
		return iterator(_cmd_node, min_node(getRoot()));
	}
	const_iterator begin() const {
		return const_iterator(_cmd_node, min_node(getRoot()));
	}
	iterator end() {
		return iterator(_cmd_node, _cmd_node->right);
	}
	const_iterator end() const {
		return const_iterator(_cmd_node, _cmd_node->right);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(_cmd_node, min_node(getRoot()));
	}
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(_cmd_node, min_node(getRoot()));
	}
	reverse_iterator rend() {
		return reverse_iterator(_cmd_node, _cmd_node->right);
	}
	const_reverse_iterator rend() const {
		return const_reverse_iterator(_cmd_node, _cmd_node->right);
	}

// Capacity:
	bool empty() const {
		return _size == 0;
	}
	size_type size() const {
		return _size;
	}
	size_type max_size() const {
		return _node_alloc.max_size();
	}

// Modifiers:
	pair<iterator,bool> insert(const value_type& val) {

	}
	iterator insert(iterator position, const value_type& val) {

	}
	template<typename InputIterator>
	void insert(InputIterator first, InputIterator last) {

	}

	node_pointer min_node(node_pointer node) const {
		if (node == 0)
			return 0;
		while (node->left != 0)
			node = node->left;
		return node;
	}
	node_pointer max_node(node_pointer node) const {
		if (node == 0)
			return 0;
		while (node->right != 0)
			node = node->right;
		return node;
	}

	node_pointer getRoot() const {
		return _cmd_node->left;
	}
	node_pointer getEnd() const {
		return _cmd_node->right;
	}

	void copy_tree(node_pointer node) {
		if (node != 0) {
			insert_value(node->value);
			copy_tree(node->left);
			copy_tree(node->right);
		}
	}


};

}

#endif
