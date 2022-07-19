/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 20:52:27 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/19 22:58:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

# include <functional>
# include <memory>

# include "utils.hpp"
# include "equal.hpp"
# include "lexicographical_compare.hpp"
# include "pair.hpp"
# include "iterator.hpp"
# include "red_black_tree.hpp"

namespace ft {

template<typename T, typename Compare = std::less<T>, typename Alloc = std::allocator<T> >
class set {
public:
	typedef T											key_type;
	typedef T											value_type;
	typedef Compare										key_compare;
	typedef Compare										value_compare;
	typedef std::allocator<T>							allocator_type;
	typedef T&											reference;
	typedef const T&									const_reference;
	typedef T*											pointer;
	typedef const T*									const_pointer;
	typedef tree_const_iterator<T>						iterator;
	typedef tree_const_iterator<T>						const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
	typedef std::ptrdiff_t								difference_type;
	typedef size_t										size_type;

private:
	key_compare _comp;
	allocator_type _alloc;
	red_black_tree<value_type, value_compare> _tree;

public:
	explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	  : _comp(comp), _alloc(alloc), _tree(comp) {}
	template<typename InputIterator>
	set(InputIterator first, InputIterator last,  const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
	  : _comp(comp), _alloc(alloc), _tree(comp) {
		_tree.insert(first, last);
	}
	set(const set& x)
	  : _comp(x._comp), _alloc(x._alloc), _tree(x._tree) {}

	~set() {}

	set& operator=(const set& x) {
		if (this == &x)
			return *this;
		_comp = x._comp;
		_alloc = x._alloc;
		_tree = x._tree;
		return *this;
	}

// Iterators:
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

// Modifiers:
	pair<iterator, bool> insert(const value_type& val) {
		return _tree.insert(val);
	}
	iterator insert(iterator position, const value_type& val) {
		(void)position;
		return _tree.insert(val).first;
	}
template <class InputIterator>
	void insert (InputIterator first, InputIterator last) {
		return _tree.insert(first, last);
	}

	void erase(iterator position) {
		return _tree.erase(position);
	}
	size_type erase(const value_type& k) {
		return _tree.erase(k);
	}
	void erase(iterator first, iterator last) {
		return _tree.erase(first, last);
	}

	void swap (set& x) { return (_tree.swap(x._tree)); }
	void clear() { return (_tree.clear()); }

// Observers:
	key_compare				key_comp() const { return (key_compare()); }
	value_compare value_comp() const {
		return value_compare();
	}

// Operations:
	iterator find (const value_type& k) const {
		return _tree.find(k);
	}
	size_type count (const value_type& k) const {
		return _tree.count(k);
	}
	iterator lower_bound (const value_type& k) const {
		const_iterator it1 = begin();
		const_iterator it2 = end();
		while (it1 != it2) 	{
			if (_comp(*it1, k) == false)
				break;
			++it1;
		}
		return iterator(it1);
	}
	iterator upper_bound (const value_type& k) const {
		const_iterator it1 = begin();
		const_iterator it2 = end();
		while (it1 != it2) {
			if (_comp(k, *it1) == true)
				break;
			++it1;
		}
		return iterator(it1);
	}
	pair<iterator,iterator>	equal_range (const value_type& k) const {
		return ft::make_pair(lower_bound(k), upper_bound(k));
	}
	allocator_type 			get_allocator() const {
		return allocator_type();
	}
};

template< class Key, class Compare, class Alloc >
void swap( ft::set<Key,Compare,Alloc>& lhs, ft::set<Key,Compare,Alloc>& rhs) {
	lhs.swap(rhs);
}

template< class Key, class Compare, class Alloc >
bool operator==( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}
template< class Key, class Compare, class Alloc >
bool operator!=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) {
	return !(lhs == rhs);
}
template< class Key, class Compare, class Alloc >
bool operator<( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template< class Key, class Compare, class Alloc >
bool operator<=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) {
	return !(rhs < lhs);
}
template< class Key, class Compare, class Alloc >
bool operator>( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) {
	return rhs < lhs;
}
template< class Key, class Compare, class Alloc >
bool operator>=( const ft::set<Key,Compare,Alloc>& lhs, const ft::set<Key,Compare,Alloc>& rhs) {
	return !(lhs < rhs);
}

}

#endif
