/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:13:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/07 22:16:55 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <memory>
# include <cstddef>

# include "iterator.hpp"
# include "utils.hpp"
# include "pair.hpp"

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
		while (_node->parent != _cmd_node && _node != _node->parent->left)
			_node = _node->parent;
		if (_node->parent != _cmd_node)
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
		while (_node->parent != _cmd_node && _node != _node->parent->right)
			_node = _node->parent;
		if (_node->parent != _cmd_node)
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
		while (_node->parent != _cmd_node && _node != _node->parent->left)
			_node = _node->parent;
		if (_node->parent != _cmd_node)
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
		while (_node->parent != _cmd_node && _node != _node->parent->right)
			_node = _node->parent;
		if (_node->parent != _cmd_node)
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
		return insertValue(val);
	}
	iterator insert(iterator position, const value_type& val) {
		(void)position;
		return insertValue(val).first;
	}
	template<typename InputIterator>
	void insert(InputIterator first, InputIterator last) {
		while (first != last) {
			insertValue(*first);
			first++;
		}
	}

// tree에 일단 node를 삽입하고 pair를 반환하는 함수
	pair<iterator, bool> insertNode(const node_pointer node) {
		node_pointer parser = getRoot();
		node_pointer parent;
		if (parser == 0) {
			setRoot(node);
			return make_pair(iterator(node), true);
		}
		while (parser != 0) {
			if (_comp(parser->value, node->value)) {
				parent = parser;
				parser = parser->right;
			} else if (_comp(node->value, parser->value)) {
				parent = parser;
				parser = parser->left;
			} else
				return make_pair(iterator(parser), false);
		}
		if (_comp(parent->value, node->value)) {
			parent->right = node;
			node->parent = parent;
		} else {
			parent->left = node;
			node->parent = parent;
		}
		return (make_pair(iterator(node), true));
	}

	void rotateLeft(node_pointer node) {
		node_pointer rightChild = node->right;
		if (rightChild == 0)
			return ;
		node->right = rightChild->left;
		if (node->right != 0)
			node->right->parent = node;
		rightChild->parent = node->parent;
		if (node == getRoot())
			setRoot(rightChild);
		else if (node == node->parent->left)
			node->parent->left = rightChild;
		else
			node->parent->right = rightChild;
		rightChild->left = node;
		node->parent = rightChild;
	}
	void rotateRight(node_pointer node) {
		node_pointer leftChild = node->left;
		if (leftChild == 0)
			return ;
		node->left = leftChild->right;
		if (node->left != 0)
			node->left->parent = node;
		leftChild->parent = node->parent;
		if (node == getRoot())
			setRoot(leftChild);
		else if (node == node->parent->right)
			node->parent->right = leftChild;
		else
			node->parent->left = leftChild;
		leftChild->right = node;
		node->parent = leftChild;
	}

	void insert_red_uncle(node_pointer& node) {
		setColor(getParent(node), BLACK);
		setColor(getUncle(node), BLACK);
		setColor(getGrandparent(node), RED);
		node = getGrandparent(node);
	}
	void insert_black_uncle_right_node(node_pointer& node, node_pointer& parent) {
		if (parent == getGrandparent(node)->left) {
			rotateLeft(parent);
			//node = parent;
			//parent = getParent(node);
		} else (parent == getGrandparent(node)->right) {
			rotateRight(parent);
			//node = parent;
			//parent = getParent(node);
		}
	}
	void insert_black_uncle_left_node(node_pointer& node, node_pointer& parent, node_pointer& g_parent) {
		if (parent == g_parent->left)
			rotateRight(g_parent);
		else
			rotateLeft(g_parent);
		setColor(parent, BLACK);
		setColor(g_parent, RED);
		node = g_parent;
	}

	void fixAfterInsert(node_pointer node) {
		node_pointer parent, g_parent, uncle;
		while (node != getRoot() && getColor(node) == RED && getColor(getParent(node)) == RED) {
			parent = getParent(node);
			g_parent = getGrandparent(node);
			if (g_parent == 0)
				break;
			uncle = getUncle(node);
			if (getColor(uncle) == RED) {
				insert_red_uncle(node);
			} else if (parent == g_parent->left) {
				if (node == parent->right)
					insert_black_uncle_right_node(node, parent);
				insert_black_uncle_left_node(node, parent, g_parent);
			} else if (parent == g_parent->right) {
				if (node == parent->left)
					insert_black_uncle_right_node(node, parent);
				insert_black_uncle_left_node(node, parent, g_parent);
			}
		}
		setColor(getRoot(), BLACK);
	}

// tree에 val값의 노드를 만들어 삽입하고 균형을 맞춤
	pair<iterator, bool> insertValue(const value_type& val) {
		node_pointer node = _node_alloc.allocate(1);
		_node_alloc.construct(node, node_type(val));
		pair<iterator, bool> ret = insertNode(node);
		if (ret.second == true) {
			_size++;
			fixAfterInsert(node);
		} else {
			_node_alloc.destroy(node);
			_node_alloc.allocate(node, 1);
		}
		return ret;
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
	void setRoot(node_pointer node) {
		_cmd_node->left = node;
		if (node != 0)
			node->parent = _cmd_node;
	}
	Color getColor(node_pointer node) {
		if (node == 0)
			return BLACK;
		return node->color;
	}
	void setColor(node_pointer node, Color color) {
		if (node == 0)
			return;
		node->color = color;
	}
	node_pointer getParent(node_pointer node) {
		if (node == 0 || node == getRoot())
			return 0;
		return node->parent;
	}
	node_pointer getGrandparent(node_pointer node) {
		node_pointer parent = getParent(node);
		if (parent == 0)
			return 0;
		return getParent(parent);
	}
	node_pointer getSibling(node_pointer node) {
		node_pointer parent = getParent(node);
		if (parent == 0)
			return 0;
		if (node == parent->left)
			return parent->right;
		return parent->left;
	}
	node_pointer getUncle(node_pointer node) {
		node_pointer parent = getParent(node);
		if (parent = 0)
			return 0;
		return getSibling(parent);
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
