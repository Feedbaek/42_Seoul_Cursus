/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:13:04 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/15 10:55:35 by minskim2         ###   ########.fr       */
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
class tree_const_iterator;

template<typename T>
class tree_iterator : public iterator<bidirectional_iterator_tag, T> {
private:
	typedef tree_node<T>	node_type;
	typedef tree_node<T>*	node_pointer;

public:
	typedef bidirectional_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef value_type&					reference;
	typedef std::ptrdiff_t				difference_type;
	typedef T*							pointer;

private:
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
	tree_iterator() : _node(0) {}
	tree_iterator(const tree_iterator& a) : _node(a._node) {}
	explicit tree_iterator(const tree_const_iterator<T>& a) {
		_node = a.base();
	}
	tree_iterator(node_pointer node) : _node(node) {}

	virtual ~tree_iterator() {}

	tree_iterator& operator=(const tree_iterator& a) {
		if (this != &a)
			_node = a._node;
		return *this;
	}
	tree_iterator& operator=(const tree_const_iterator<T>& a) {
		if (this != &a)
			_node = a.base();
		return *this;
	}

	tree_iterator& operator++() {
		if (_node->right != 0) {
			_node = min_node(_node->right);
			return *this;
		}
		while (_node->parent && _node != _node->parent->left)
			_node = _node->parent;
		if (_node->parent)
			_node = _node->parent;
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
		while (_node->parent && _node != _node->parent->right)
			_node = _node->parent;
		if (_node->parent)
			_node = _node->parent;
		else
			_node = 0;
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
};

template<typename T>
class tree_const_iterator : public iterator<bidirectional_iterator_tag, T> {
private:
	typedef tree_node<T>				node_type;
	typedef tree_node<T>*				node_pointer;

public:
	typedef bidirectional_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef const T&					reference;
	typedef std::ptrdiff_t				difference_type;
	typedef const T*					pointer;

private:
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
	tree_const_iterator() : _node(0) {}
	tree_const_iterator(const tree_const_iterator& a) : _node(a._node) {}
	tree_const_iterator(const tree_iterator<T>& a) {
		_node = a.base();
	}
	tree_const_iterator(node_pointer node) : _node(node) {}

	virtual ~tree_const_iterator() {}

	tree_const_iterator& operator=(const tree_const_iterator& a) {
		if (this != &a)
			_node = a._node;
		return *this;
	}
	tree_const_iterator& operator=(const tree_iterator<T>& a) {
		if (this != &a)
			_node = a._node;
		return *this;
	}

	tree_const_iterator& operator++() {
		if (_node->right != 0) {
			_node = min_node(_node->right);
			return *this;
		}
		while (_node->parent && _node != _node->parent->left)
			_node = _node->parent;
		if (_node->parent)
			_node = _node->parent;
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
		while (_node->parent && _node != _node->parent->right)
			_node = _node->parent;
		if (_node->parent)
			_node = _node->parent;
		else
			_node = 0;
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

	node_pointer base() const {
		return _node;
	}
};

template<typename T, typename Compare>
class red_black_tree {
private:
	typedef red_black_tree								rbtree;
	typedef tree_node<T>								node_type;
	typedef tree_node<T>*								node_pointer;
	typedef std::allocator<node_type>					node_alloc_type;

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

private:
	value_compare _comp;
	allocator_type _alloc;
	node_alloc_type _node_alloc;
	node_pointer _cmd_node;  // left == root
	size_type _size;

public:
	red_black_tree(const value_compare& comp)
	  : _comp(comp), _alloc(allocator_type()), _node_alloc(node_alloc_type()), _cmd_node(0), _size(0) {
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

	void copy_tree(node_pointer node) {
		if (node != 0) {
			insertValue(node->value);
			copy_tree(node->left);
			copy_tree(node->right);
		}
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
		_size = a._size;
		return *this;
	}

// Iterators:
	iterator begin() {
		return iterator(min_node(_cmd_node));
	}
	const_iterator begin() const {
		return const_iterator(min_node(_cmd_node));
	}
	iterator end() {
		return iterator(_cmd_node);
	}
	const_iterator end() const {
		return const_iterator(_cmd_node);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(end());
	}
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(end());
	}
	reverse_iterator rend() {
		return reverse_iterator(begin());
	}
	const_reverse_iterator rend() const {
		return const_reverse_iterator(begin());
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
			insertValue(*(first++));
		}
	}

	void erase(const_iterator position) {
		deleteValue(*position);
	}
	size_type erase(const value_type& k) {
		return deleteValue(k);
	}
	void erase(const_iterator first, const_iterator last) {
		for (const_iterator it = first; it != last; ) {
			erase(it++);
		}
	}

	void swap(rbtree& x) {
		if (this == &x)
			return;
		value_compare	tmp_comp = x._comp;
		node_alloc_type	tmp_node_alloc = x._node_alloc;
		node_pointer	tmp_cmd_node = x._cmd_node;
		size_type		tmp_size = x._size;

		x._comp = _comp;
		x._node_alloc = _node_alloc;
		x._cmd_node = _cmd_node;
		x._size = _size;

		_comp = tmp_comp;
		_node_alloc = tmp_node_alloc;
		_cmd_node = tmp_cmd_node;
		_size = tmp_size;
	}
	void clear() {
		deleteTree(getRoot());
		setRoot(0);
		_size = 0;
	}
	iterator find(const value_type& k) const {
		node_pointer tmp = getRoot();
		while (tmp != 0) {
			if (!_comp(tmp->value, k) && !_comp(k, tmp->value))
				break;
			else if (_comp(tmp->value, k))
				tmp = tmp->right;
			else
				tmp = tmp->left;
		}
		if (tmp == 0)
			return (iterator(_cmd_node));
		return (iterator(tmp));
	}
	size_type count(const value_type& k) const {
		iterator tmp = find(k);
		if (tmp == end())
			return 0;
		size_type cnt = 0;
		for (iterator it = tmp; it != end(); ++it) {
			if (!_comp(*it, k) && !_comp(k, *it))
				++cnt;
		}
		return cnt;
	}

private:
	void deleteTree(node_pointer node) {
		if (node == 0)
			return;
		deleteTree(node->left);
		deleteTree(node->right);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
	}

	node_pointer deleteNode(node_pointer node, const value_type& val) {
		node_pointer tmp1, tmp2;
		Color color;
		if (node == 0)
			return 0;
		if (_comp(node->value, val))
			return deleteNode(node->right, val);
		if (_comp(val, node->value))
			return deleteNode(node->left, val);
		if (node->left == 0 || node->right == 0)
			return node;
		tmp1 = min_node(node->right);
		if (tmp1->parent == node) {
			if (node->parent->left == node)
				node->parent->left = tmp1;
			if (node->parent->right == node)
				node->parent->right = tmp1;
			tmp1->left = node->left;
			node->left->parent = tmp1;
			node->left = 0;
			tmp1->parent = node->parent;
			node->parent = tmp1;
			node->right = tmp1->right;
			tmp1->right = node;
			color = tmp1->color;
			tmp1->color = node->color;
			node->color = color;
		} else {
			if (node->parent->left == node)
				node->parent->left = tmp1;
			if (node->parent->right == node)
				node->parent->right = tmp1;
			if (tmp1->parent->left == tmp1)
				tmp1->parent->left = node;
			if (tmp1->parent->right == tmp1)
				tmp1->parent->right = node;
			tmp2 = tmp1->parent;
			node->right->parent = tmp1;
			tmp1->parent = node->parent;
			node->parent = tmp2;
			tmp1->left = node->left;
			node->left->parent = tmp1;
			node->left = 0;
			tmp2 = tmp1->right;
			tmp1->right = node->right;
			node->right = tmp2;
			color = tmp1->color;
			tmp1->color = tmp2->color;
			tmp2->color = color;
		}
		return deleteNode(tmp1->right, val);
	}

	void delete_red_case(node_pointer& node) {
		node_pointer child;
		if (node->left != 0)
			child = node->left;
		else
			child = node->right;
		if (node == node->parent->left)
			node->parent->left = child;
		else
			node->parent->right = child;
		if (child != 0)
			child->parent = node->parent;
		setColor(child, BLACK);
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
	}
	void delete_root_case(node_pointer root) {
		if (root->right)
			setRoot(root->right);
		else
			setRoot(root->left);
		_node_alloc.destroy(root);
		_node_alloc.deallocate(root, 1);
		setColor(getRoot(), BLACK);
		return;
	}

	void deleteCase1(node_pointer& s, node_pointer& p) {
		setColor(s, BLACK);
		setColor(p, RED);
		if (s == p->right)
			rotateLeft(p);
		if (s == p->left)
			rotateRight(p);
	}
	void deleteCase2(node_pointer s, node_pointer p, node_pointer& node) {
		setColor(s, RED);
		if (getColor(p) == RED)
			setColor(p, BLACK);
		else
			setColor(p, DBLACK);
		node = p;
	}
	void deleteCase3(node_pointer& s, node_pointer& p) {
		if (s == p->right) {
			setColor(s->left, BLACK);
			setColor(s, RED);
			rotateRight(s);
			s = p->right;
		}
		if (s == p->left) {
			setColor(s->right, BLACK);
			setColor(s, RED);
			rotateLeft(s);
			s = p->left;
		}
	}
	void deleteCase4(node_pointer& s, node_pointer& p) {
		if (s == p->right) {
			setColor(s, getColor(p));
			setColor(p, BLACK);
			setColor(s->right, BLACK);
			rotateLeft(p);
		}
		if (s == p->left) {
			setColor(s, getColor(p));
			setColor(p, BLACK);
			setColor(s->left, BLACK);
			rotateRight(p);
		}
	}

	void fixAfterDelete(node_pointer node) {
		if (node == 0)
			return;
		if (node == getRoot()) {
			delete_root_case(node);
			return;
		}
		if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED) {
			delete_red_case(node);
			return ;
		}
		node_pointer s=0, p=0, tmp=node;
		setColor(tmp, DBLACK);
		while (tmp != getRoot() && getColor(tmp) == DBLACK) {
			p = tmp->parent;
			if (tmp == p->left)
				s = p->right;
			else
				s = p->left;
			if (getColor(s) == RED)
				deleteCase1(s, p);
			else if (getColor(s->left) == BLACK && getColor(s->right) == BLACK)
				deleteCase2(s, p, tmp);
			else {
				if ((tmp == p->left && getColor(s->right) == BLACK)
				|| (tmp == p->right && getColor(s->left) == BLACK))
					deleteCase3(s, p);
				deleteCase4(s, p);
				break;
			}
		}
		if (node == node->parent->left)
			node->parent->left = 0;
		else
			node->parent->right = 0;
		_node_alloc.destroy(node);
		_node_alloc.deallocate(node, 1);
		setColor(getRoot(), BLACK);
	}

	size_type deleteValue(const value_type& val) {
		node_pointer target = deleteNode(getRoot(), val);
		if (target == 0)
			return 0;
		fixAfterDelete(target);
		_size--;
		return 1;
	}

// tree에 일단 node를 삽입하고 pair를 반환하는 함수
	pair<iterator, bool> insertNode(node_pointer node) {
		node_pointer tmp = getRoot();
		node_pointer parent;
		if (tmp == 0) {
			setRoot(node);
			return ft::make_pair(iterator(node), true);
		}
		while (tmp) {
			if (_comp(tmp->value, node->value)) {
				parent = tmp;
				tmp = tmp->right;
			} else if (_comp(node->value, tmp->value)) {
				parent = tmp;
				tmp = tmp->left;
			} else
				return ft::make_pair(iterator(tmp), false);
		}
		if (_comp(parent->value, node->value)) {
			parent->right = node;
			node->parent = parent;
		} else {
			parent->left = node;
			node->parent = parent;
		}
		return (ft::make_pair(iterator(node), true));
	}

	void rotateLeft(node_pointer node) {
		node_pointer rightChild = node->right;
		if (rightChild == 0)
			return ;
		node->right = rightChild->left;
		if (node->right != 0)
			node->right->parent = node;
		rightChild->parent = node->parent;
		if (getParent(node) == 0)
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
		if (getParent(node) == 0)
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
			node = parent;
			parent = getParent(node);
		}
		if (parent == getGrandparent(node)->right) {
			rotateRight(parent);
			node = parent;
			parent = getParent(node);
		}
	}
	void insert_black_uncle_left_node(node_pointer& node, node_pointer& parent, node_pointer& g_parent) {
		if (parent == g_parent->left)
			rotateRight(g_parent);
		if (parent == g_parent->right)
			rotateLeft(g_parent);
		Color tmp = getColor(parent);
		setColor(parent, getColor(g_parent));
		setColor(g_parent, tmp);
		node = parent;
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
		if (ret.second == false) {
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		} else {
			_size++;
			fixAfterInsert(node);
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
		_cmd_node->right = node;
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
		if (node == 0 || node->parent == _cmd_node)
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
		if (parent == 0)
			return 0;
		return getSibling(parent);
	}

};

}

#endif
