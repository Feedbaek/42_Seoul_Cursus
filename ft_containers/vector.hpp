/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:04:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/19 21:07:52 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>
# include <iterator>
# include <string>
# include <limits>

# include "iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "utils.hpp"

namespace ft {

template<typename T>
class const_vector_iterator;
template<typename T>
class vector_iterator;

template<typename T>
class vector_iterator : public ft::iterator<random_access_iterator_tag, T> {
public:
	typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename iterator<random_access_iterator_tag, T>::value_type			value_type;
	typedef typename iterator<random_access_iterator_tag, T>::reference				reference;
	typedef typename iterator<random_access_iterator_tag, T>::pointer				pointer;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type		difference_type;

protected:
	pointer p;

public:
	vector_iterator(): p(0) {}
	vector_iterator(pointer a): p(a) {}
	vector_iterator(const vector_iterator& a) : p(a.p) {}
	explicit vector_iterator(const const_vector_iterator<T>& a) {
		p = a.base();
	}
	vector_iterator& operator=(const vector_iterator& a) {
		p = a.p;
		return *this;
	}
	vector_iterator& operator=(const const_vector_iterator<T>& a) {
		p = a.base();
		return *this;
	}
	bool operator==(const vector_iterator& a) const {
		return p == a.p;
	}
	bool operator==(const const_vector_iterator<T>& a) const {
		return p == a.base();
	}
	bool operator!=(const vector_iterator& a) const {
		return p != a.p;
	}
	bool operator!=(const const_vector_iterator<T>& a) const {
		return p != a.base();
	}
	reference operator*() const {
		return *p;
	}
	pointer operator->() const {
		return p;
	}
	vector_iterator& operator++() {
		++p;
		return *this;
	}
	vector_iterator operator++(int) {
		vector_iterator tmp(*this);
		++p;
		return tmp;
	}
	vector_iterator& operator--() {
		--p;
		return *this;
	}
	vector_iterator operator--(int) {
		vector_iterator tmp(*this);
		--p;
		return tmp;
	}
	vector_iterator operator+(difference_type n) {
		vector_iterator tmp(*this);
		return tmp += n;
	}
	vector_iterator operator-(difference_type n) {
		vector_iterator tmp(*this);
		return tmp -= n;
	}
	difference_type operator-(const vector_iterator& a) const {
		return p - a.p;
	}
	difference_type operator-(const const_vector_iterator<T>& a) const {
		return p - a.base();
	}
	bool operator<(const vector_iterator& a) const {
		return p < a.p;
	}
	bool operator<(const const_vector_iterator<T>& a) const {
		return p < a.base();
	}
	bool operator>(const vector_iterator& a) const {
		return p > a.p;
	}
	bool operator>(const const_vector_iterator<T>& a) const {
		return p > a.base();
	}
	bool operator<=(const vector_iterator& a) const {
		return p <= a.p;
	}
	bool operator<=(const const_vector_iterator<T>& a) const {
		return p <= a.base();
	}
	bool operator>=(const vector_iterator& a) const {
		return p >= a.p;
	}
	bool operator>=(const const_vector_iterator<T>& a) const {
		return p >= a.base();
	}
	vector_iterator& operator+=(difference_type n) {
		p += n;
		return *this;
	}
	vector_iterator& operator-=(difference_type n) {
		p -= n;
		return *this;
	}
	reference operator[](difference_type n) {
		return *(p + n);
	}

	pointer base() const {
		return p;
	}
};

template<typename T>
class const_vector_iterator : public ft::iterator<random_access_iterator_tag, T> {
public:
	typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
	typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
	typedef const value_type&													reference;
	typedef const value_type*													pointer;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;

protected:
	pointer p;

public:
	const_vector_iterator(): p(0) {}
	const_vector_iterator(pointer a): p(a) {}
	const_vector_iterator(const const_vector_iterator& a) : p(a.p) {}
	const_vector_iterator(const vector_iterator<T>& a) {
		p = a.base();
	}
	const_vector_iterator& operator=(const const_vector_iterator& a) {
		p = a.p;
		return *this;
	}
	const_vector_iterator& operator=(const vector_iterator<T>& a) {
		p = a.base();
		return *this;
	}
	bool operator==(const const_vector_iterator& a) const {
		return p == a.p;
	}
	bool operator==(const vector_iterator<T>& a) const {
		return p == a.base();
	}
	bool operator!=(const const_vector_iterator& a) const {
		return p != a.p;
	}
	bool operator!=(const vector_iterator<T>& a) const {
		return p != a.base();
	}
	reference operator*() const {
		return *p;
	}
	pointer operator->() const {
		return p;
	}
	const_vector_iterator& operator++() {
		++p;
		return *this;
	}
	const_vector_iterator operator++(int) {
		const_vector_iterator tmp(*this);
		++p;
		return tmp;
	}
	const_vector_iterator& operator--() {
		--p;
		return *this;
	}
	const_vector_iterator operator--(int) {
		const_vector_iterator tmp(*this);
		--p;
		return tmp;
	}
	const_vector_iterator operator+(difference_type n) {
		const_vector_iterator tmp(*this);
		return tmp += n;
	}
	const_vector_iterator operator-(difference_type n) {
		const_vector_iterator tmp(*this);
		return tmp -= n;
	}
	difference_type operator-(const const_vector_iterator& a) const {
		return p - a.p;
	}
	difference_type operator-(const vector_iterator<T>& a) const {
		return p - a.base();
	}
	bool operator<(const const_vector_iterator& a) const {
		return p < a.p;
	}
	bool operator<(const vector_iterator<T>& a) const {
		return p < a.base();
	}
	bool operator>(const const_vector_iterator& a) const {
		return p > a.p;
	}
	bool operator>(const vector_iterator<T>& a) const {
		return p > a.base();
	}
	bool operator<=(const const_vector_iterator& a) const {
		return p <= a.p;
	}
	bool operator<=(const vector_iterator<T>& a) const {
		return p <= a.base();
	}
	bool operator>=(const const_vector_iterator& a) const {
		return p >= a.p;
	}
	bool operator>=(const vector_iterator<T>& a) const {
		return p >= a.base();
	}
	const_vector_iterator& operator+=(difference_type n) {
		p += n;
		return *this;
	}
	const_vector_iterator& operator-=(difference_type n) {
		p -= n;
		return *this;
	}
	reference operator[](difference_type n) {
		return *(p + n);
	}

	pointer base() const {
		return p;
	}
};

template<typename T>
vector_iterator<T> operator+(typename vector_iterator<T>::difference_type n, const vector_iterator<T>& iterator) { vector_iterator<T> itr = iterator; return (itr + n); }
template<typename T>
const_vector_iterator<T> operator+(typename const_vector_iterator<T>::difference_type n, const const_vector_iterator<T>& iterator) { const_vector_iterator<T> itr = iterator; return (itr + n); }

template<typename T, typename Alloc = std::allocator<T> >
class vector {
public:
	typedef T													value_type;
	typedef std::allocator<value_type>							allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef vector_iterator<value_type>							iterator;
	typedef const_vector_iterator<value_type>					const_iterator;
	typedef ft::reverse_iterator<iterator>						reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t												size_type;

private:
	allocator_type _alloc;
	pointer _container;
	size_type _capacity;
	size_type _size;

public:
	explicit vector()
		: _alloc(allocator_type()), _container(0), _capacity(0), _size(0) {}
	explicit vector(size_type n, const value_type& val=value_type())
		: _alloc(allocator_type()), _container(0), _capacity(0), _size(0) {
		_container = _alloc.allocate(n);
		for (size_type i=0; i<n; i++)
			_alloc.construct(_container + i, val);
		_capacity = n;
		_size = n;
	}
	template<typename Iter>
	vector(Iter first, Iter last, typename enable_if<!is_integral<Iter>::value, Iter>::type* = 0)
		: _alloc(allocator_type()), _container(0), _capacity(0), _size(0) {
		insert(_container, first, last);
	}
	vector(const vector& a)
		: _alloc(allocator_type()), _container(0), _capacity(0), _size(0) {
		insert(_container, a.begin(), a.end());
	}
	~vector() {
		clear();
		if (_container != 0)
			_alloc.deallocate(_container, _capacity);
		_capacity = 0;
		_container = 0;
	}

	vector& operator=(const vector& a) {
		if (&a == this)
			return *this;
		clear();
		if (_container != 0)
			_alloc.deallocate(_container, _capacity);
		_capacity = 0;
		_container = 0;
		assign(a.begin(), a.end());
		return (*this);
	}

	// Iterators:

	iterator begin() {
		return iterator(this->_container);
	}
	const_iterator begin() const {
		return const_iterator(this->_container);
	}
	iterator end() {
		return iterator(this->_container + this->_size);
	}
	const_iterator end() const {
		return const_iterator(this->_container + this->_size);
	}
	reverse_iterator rbegin() {
		return reverse_iterator(this->end());
	}
	const_reverse_iterator rbegin() const {
		return const_reverse_iterator(this->end());
	}
	reverse_iterator rend() {
		return reverse_iterator(this->begin());
	}
	const_reverse_iterator rend() const {
		return const_reverse_iterator(this->begin());
	}

	// Capacity:

	size_type size() const {
		return this->_size;
	}
	size_type max_size() const {
		return _alloc.max_size();
		//if ((size_type) std::numeric_limits<difference_type>::max() < std::numeric_limits<size_type>::max() / sizeof(value_type))
		//	return (size_type) std::numeric_limits<difference_type>::max();
		//return std::numeric_limits<size_type>::max() / sizeof(value_type);
	}
	void resize(size_type n, value_type val = value_type()) {
		if (n > _capacity) {
			if (n < 2 * _capacity)
				reserve(2 * _capacity);
			else
				reserve(n);
		}
		if (n > _size) {
			for (size_type i=_size; i<n; i++)
				_alloc.construct(_container + i, val);
			_size = n;
		} else if (n < _size) {
			for (size_type i=n; i<_size; i++)
				_alloc.destroy(_container + i);
			_size = n;
		}
	}
	size_type capacity() const {
		return _capacity;
	}
	bool empty() const {
		return _size == 0;
	}
	void reserve(size_type n) {
		if (n > max_size())
			throw std::length_error("Error -> vector::reserve");
		if (n > _capacity) {
			pointer _new_container = _alloc.allocate(n);
			for (size_type i=0; i<_size; i++) {
				_alloc.construct(_new_container + i, *(_container + i));
				_alloc.destroy(_container + i);
			}
			if (_container != 0)
				_alloc.deallocate(_container, _capacity);
			_container = _new_container;
			_capacity = n;
		}
	}

	// Elememt access:

	reference operator[](size_type n) {
		return *(_container + n);
	}
	const_reference operator[](size_type n) const {
		return *(_container + n);
	}
	reference at(size_type n) {
		if (n >= _size)
			throw std::out_of_range("Error -> vector:at");
		return *(_container + n);
	}
	const_reference at(size_type n) const {
		if (n >= _size)
			throw std::out_of_range("Error -> vector:at");
		return *(_container + n);
	}
	reference front() {
		return *(_container);
	}
	const_reference front() const {
		return *(_container);
	}
	reference back() {
		return *(_container + _size - 1);
	}
	const_reference back() const {
		return *(_container + _size - 1);
	}

	// Modifiers:

	template<typename InputIterator>
	void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0) {
		clear();
		size_type d_size = ft::distance(first, last);
		if (d_size <= _capacity)
			for (size_type i=0; &*first != &*last; ++first, ++i)
				_alloc.construct(_container + i, *first);
		else {
			reserve(d_size);
			for (size_type i=0; &*first != &*last; ++first, ++i)
				_alloc.construct(_container + i, *first);
		}
		_size = d_size;
	}
	void assign(size_type n, const value_type& val) {
		clear();
		if (n > _capacity)
			reserve(n);
		for (size_type i=0; i<n; i++)
			_alloc.construct(_container + i, val);
		_size = n;
	}
	void push_back(const value_type& val) {
		if (_size == _capacity) {
			if (_size == 0)
				reserve(1);
			else
				reserve(_size * 2);
		}
		_alloc.construct(_container + _size, val);
		_size++;
	}
	void pop_back() {
		_alloc.destroy(_container + _size - 1);
		_size--;
	}
	iterator insert(iterator position, const value_type& val) {
		size_type rlen = (_container + _size) - &(*position);
		size_type llen = &(*position) - _container;
		pointer _new_container = _container;
		size_type _new_capacity = _capacity;
		if (_size == max_size())
			throw std::length_error("Error -> vector::insert(single element)");
		if (_size == 0) {
			_new_container = _alloc.allocate(1);
			_new_capacity = 1;
		} else if (_size == _capacity) {
			_new_container = _alloc.allocate(_size * 2);
			_new_capacity *= 2;
		}
		// position 이전 값들 옮기기
		if (_container != _new_container)
			for (size_type i=0; i<llen; i++) {
				_alloc.construct(_new_container + i, *(_container + i));
				_alloc.destroy(_container + i);
			}
		// position 이후 값들 옮기기
		for (size_type i=0; i<rlen; i++) {
			_alloc.construct(_new_container + _size - i, *(_container + _size-1 - i));
			_alloc.destroy(_container + _size-1 - i);
		}
		// 새로운 값 추가
		_alloc.construct(_new_container + llen, val);
		if (_container != _new_container && _container != 0)
			_alloc.deallocate(_container, _capacity);
		_container = _new_container;
		_capacity = _new_capacity;
		_size++;
		return (iterator(_container + llen));
	}
	void insert(iterator position, size_type n, const value_type& val) {
		size_type rlen = (_container + _size) - &(*position);
		size_type llen = &(*position) - _container;
		pointer _new_container = _container;
		size_type _new_capacity = _capacity;
		if (n == 0)
			return ;
		if (_size + n > max_size())
			throw std::length_error("Error -> vector::insert(fill)");
		if (_size + n > _capacity) {
			if (_size + n < _size * 2) {
				_new_container = _alloc.allocate(_size * 2);
				_new_capacity *= 2;
			} else {
				_new_container = _alloc.allocate(_size + n);
				_new_capacity = _size + n;
			}
		}
		// position 이전 값들 옮기기
		if (_container != _new_container)
			for (size_type i=0; i<llen; i++) {
				_alloc.construct(_new_container + i, *(_container + i));
				_alloc.destroy(_container + i);
			}
		// position 이후 값들 옮기기
		for (size_type i=0; i<rlen; i++) {
			_alloc.construct(_new_container + _size-1 + n - i, *(_container + _size-1 - i));
			_alloc.destroy(_container + _size-1 - i);
		}
		// 새로운 값 추가
		for (size_type i=0; i<n; i++)
			_alloc.construct(_new_container + llen + i, val);
		if (_container != _new_container && _container != 0)
			_alloc.deallocate(_container, _capacity);
		_container = _new_container;
		_capacity = _new_capacity;
		_size += n;
	}
	template <typename InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0) {
		size_type rlen = (_container + _size) - &(*position);
		size_type llen = &(*position) - _container;
		pointer _new_container = _container;
		size_type _new_capacity = _capacity;
		size_type num = ft::distance(first, last);
		if (num == 0)
			return ;
		if (_size + num > max_size())
			throw std::length_error("Error -> vector::insert(range)");
		if (_size + num > _capacity) {
			if (_size + num < _size * 2) {
				_new_container = _alloc.allocate(_size * 2);
				_new_capacity *= 2;
			} else {
				_new_container = _alloc.allocate(_size + num);
				_new_capacity = _size + num;
			}
		}
		// position 이전 값들 옮기기
		if (_container != _new_container)
			for (size_type i=0; i<llen; i++) {
				_alloc.construct(_new_container + i, *(_container + i));
				_alloc.destroy(_container + i);
			}
		// position 이후 값들 옮기기
		for (size_type i=0; i<rlen; i++) {
			_alloc.construct(_new_container + _size-1 + num - i, *(_container + _size-1 - i));
			_alloc.destroy(_container + _size-1 - i);
		}
		// 새로운 값 추가
		for (size_type i=0; i<num; i++)
			_alloc.construct(_new_container + llen + i, *(first++));
		if (_container != _new_container && _container != 0)
			_alloc.deallocate(_container, _capacity);
		_container = _new_container;
		_capacity = _new_capacity;
		_size += num;
	}
	iterator erase(iterator iter) {
		return erase(iter, iter + 1);
	}
	iterator erase(iterator first, iterator last) {
		size_type num = ft::distance(first, last);
		iterator _end = end();
		for (size_type i=0; i<num; i++)
			_alloc.destroy(&(*(first + i)));
		for (size_type i=0; last + i != _end; i++) {
			_alloc.construct(&(*(first + i)), *(last + i));
			_alloc.destroy(&(*(last + i)));
		}
		_size -= num;
		return first;
	}
	void swap(vector& a) {
		if (&a == this)
			return;
		pointer _tmp_container = a._container;
		size_type _tmp_size = a._size;
		size_type _tmp_capacity = a._capacity;

		a._container = _container;
		a._size = _size;
		a._capacity = _capacity;

		_container = _tmp_container;
		_size = _tmp_size;
		_capacity = _tmp_capacity;
	}
	void clear() {
		for (size_type i=0; i<_size; i++)
			_alloc.destroy(_container + i);
		_size = 0;
	}

	// Allocator:

	allocator_type get_alllocator() const {
		return _alloc;
	}

};


template<typename T>
bool operator==(const vector<T>& lhs, const vector<T>& rhs) {
	if (lhs.size() != rhs.size())
		return false;
	typename vector<T>::const_iterator first1 = lhs.begin();
	typename vector<T>::const_iterator first2 = rhs.begin();
	typename vector<T>::size_type num = lhs.size();
	for (typename vector<T>::size_type i=0; i<num; i++)
		if (*(first1 + i) != *(first2 + i))
			return false;
	return true;
}
template<typename T>
bool operator!=(const vector<T>& lhs, const vector<T>& rhs) {
	return !(lhs == rhs);
}
template<typename T>
bool operator<(const vector<T>& lhs, const vector<T>& rhs) {
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template<typename T>
bool operator<=(const vector<T>& lhs, const vector<T>& rhs) {
	return !(lhs > rhs);
}
template<typename T>
bool operator>(const vector<T>& lhs, const vector<T>& rhs) {
	return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
}
template<typename T>
bool operator>=(const vector<T>& lhs, const vector<T>& rhs) {
	return !(lhs < rhs);
}

template<typename T>
void swap(vector<T>&x, vector<T>&y) {
	x.swap(y);
}

}

#endif
