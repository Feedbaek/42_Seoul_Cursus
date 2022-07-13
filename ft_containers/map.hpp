/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:59:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/13 21:49:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <functional>

# include "red_black_tree.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"

namespace ft {

template<typename Key, typename T, typename Compare = std::less<Key>, typename Alloc = std::allocator<pair<const Key, T> > >
class map {
public:
	typedef Key				key_type;
	typedef T				mapped_type;
	typedef pair<Key, T>	value_type;
	typedef size_t			size_type;
	typedef ptrdiff_t		difference_type;
	typedef Compare			key_compare;
	typedef std::allocator<value_type>	allocator_type;

	class value_compare : public std::binary_function<value_type, value_type, bool> {
		friend class map;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef tree_iterator<value_type>					iterator;
	typedef tree_const_iterator<value_type>				const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

private:
	key_compare _comp;
	allocator_type _alloc;
	red_black_tree<value_type, value_compare> _tree;

public:
	explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	  : _comp(comp), _alloc(alloc), _tree(value_compare(comp)) {
	}
	template<typename InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	  : _comp(comp), _alloc(alloc), _tree(value_compare(comp)) {
		insert(first, last);
	}
	map(const map& x) : _comp(x._comp), _alloc(x._alloc), _tree(x._tree) {}
	~map() {}

	map& operator=(const map& x) {
		if (this == &x)
			return *this;
		_tree = x._tree;
		return *this;
	}

//Iterators:
	iterator begin() {
		return _tree.begin();
	}
	const_iterator begin() const {
		return _tree.begin();
	}
	iterator end() {
		return _tree.end();
	}
	const_iterator end() const {
		return _tree.end();
	}
	reverse_iterator rbegin() {
		return _tree.rbegin();
	}
	const_reverse_iterator rbegin() const {
		return _tree.rbegin();
	}
	reverse_iterator rend() {
		return _tree.rend();
	}
	const_reverse_iterator rend() const {
		return _tree.rend();
	}

// Capacity:
	bool empty() const {
		return _tree.empty();
	}
	size_type size() const {
		return _tree.size();
	}
	size_type max_size() const {
		return _tree.max_size();
	}

// Element access:
	mapped_type& operator[](const key_type& k) {
		return (*((insert(make_pair(k ,mapped_type()))).first)).second;
	}

// Modifiers:
	pair<iterator, bool> insert(const value_type& val) {
		return _tree.insert(val);
	}
	iterator insert(iterator position, const value_type& val) {
		return _tree.insert(position, val);
	}
	template<typename InputIterator>
	void insert(InputIterator first, InputIterator last) {
		_tree.insert(first, last);
	}
	void erase(iterator position) {
		_tree.erase(position);
	}
	size_type erase(const key_type& k) {
		return _tree.erase(make_pair(k, mapped_type()));
	}
	void erase(iterator first, iterator last) {
		_tree.erase(first, last);
	}
	void swap(map& x) {
		_tree.swap(x._tree);
	}
	void clear() {
		_tree.clear();
	}

// Observers:
	key_compare key_comp() const {
		return key_compare();
	}
	value_compare value_comp() const {
		return value_compare(key_compare());
	}

// Operations:
	iterator find(const key_type& k) {
		return _tree.find(make_pair(k, mapped_type()));
	}
	const_iterator find(const key_type& k) const {
		return _tree.find(make_pair(k, mapped_type()));
	}
	size_type count(const key_type& k) const {
		return _tree.count(make_pair(k, mapped_type()));
	}
	iterator lower_bound(const key_type& k) {
		iterator st = begin();
		iterator en = end();
		while (st != en) {
			if (_comp(st->first, k) == false)
				break;
			++st;
		}
		return st;
	}
	iterator upper_bound(const key_type& k) {
		iterator st = begin();
		iterator en = end();
		while (st != en) {
			if (_comp(k, st->first) == true)
				break;
			++st;
		}
		return st;
	}
	const_iterator lower_bound(const key_type& k) const {
		iterator st = begin();
		iterator en = end();
		while (st != en) {
			if (_comp(st->first, k) == false)
				break;
			++st;
		}
		return st;
	}
	const_iterator upper_bound(const key_type& k) const {
		iterator st = begin();
		iterator en = end();
		while (st != en) {
			if (_comp(k, st->first) == true)
				break;
			++st;
		}
		return st;
	}
	pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
		return make_pair(lower_bound(k), upper_bound(k));
	}
	pair<iterator, iterator> equal_range(const key_type& k) {
		return make_pair(lower_bound(k), upper_bound(k));
	}
	allocator_type get_allocator() const {
		return allocator_type();
	}
};

template<typename Key, typename T, typename Compare, typename Alloc>
void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
	x.swap(y);
};

template<typename Key, typename T, typename Compare, typename Alloc >
bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template<typename Key, typename T, typename Compare, typename Alloc >
bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs) {
	return !(lhs == rhs);
}
template<typename Key, typename T, typename Compare, typename Alloc >
bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}
template<typename Key, typename T, typename Compare, typename Alloc >
bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(rhs < lhs));
}
template<typename Key, typename T, typename Compare, typename Alloc >
bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (rhs < lhs);
}
template<typename Key, typename T, typename Compare, typename Alloc >
bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs) {
	return (!(lhs < rhs));
}

}

#endif
