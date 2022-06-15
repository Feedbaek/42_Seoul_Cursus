/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:04:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/15 16:57:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>
# include <iterator>

# include "iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"

namespace ft {

template<typename T>
class vector_iterator : public iterator<random_access_iterator_tag, T> {
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
	vector_iterator& operator=(const vector_iterator& a) {
		p = a.p;
		return *this;
	}
	bool operator==(const vector_iterator& a) const {
		return p == a.p;
	}
	bool operator!=(const vector_iterator& a) const {
		return p != a.p;
	}
	reference operator*() {
		return *p;
	}
	const reference operator*() const {
		return *p;
	}
	pointer operator->() {
		return p;
	}
	const pointer operator->() const {
		return p;
	}
	virtual vector_iterator& operator++() {
		++p;
		return *this;
	}
	virtual vector_iterator operator++(int) {
		vector_iterator tmp(*this);
		++p;
		return tmp;
	}
	virtual vector_iterator& operator--() {
		--p;
		return *this;
	}
	virtual vector_iterator operator--(int) {
		vector_iterator tmp(*this);
		--p;
		return tmp;
	}
	virtual vector_iterator operator+(int value) {
		vector_iterator tmp(*this);
		return tmp += value;
	}
	virtual vector_iterator operator-(int value) {
		vector_iterator tmp(*this);
		return tmp - value;
	}
	difference_type operator-(const vector_iterator& a) const {
		return p - a.p;
	}
	bool operator<(const vector_iterator& a) const {
		return p < a.p;
	}
	bool operator>(const vector_iterator& a) const {
		return p > a.p;
	}
	bool operator<=(const vector_iterator& a) const {
		return p <= a.p;
	}
	bool operator>=(const vector_iterator& a) const {
		return p >= a.p;
	}
	virtual vector_iterator& operator+=(int value) {
		p += value;
		return *this;
	}
	virtual vector_iterator& operator-=(int value) {
		p -= value;
		return *this;
	}
	virtual reference operator[](int value) {
		return *(p + value);
	}
	virtual const reference operator[](int value) const {
		return *(p + value);
	}
};

template<typename T>
class vector {

public:
	typedef T													value_type;
	typedef std::allocator<T>									allocator_type;
	typedef typename allocator_type::reference					reference;
	typedef typename allocator_type::const_reference			const_reference;
	typedef typename allocator_type::pointer					pointer;
	typedef typename allocator_type::const_pointer				const_pointer;
	typedef vector_iterator<T>									iterator;
	typedef vector_iterator<const T>							const_iterator;
	typedef vector_reverse_iterator<iterator>					reverse_iterator;
	typedef vector_reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef typename iterator_traits<iterator>::difference_type	difference_type;
	typedef size_t												 size_type;

private:
	allocator_type _alloc;
	pointer _container;
	size_type _capacity;
	size_type _size;

public:
	explicit vector(const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _container(0), _capacity(0), _size(0) {}
	explicit vector(size_type n, const value_type& val=value_type(), const allocator_type& alloc = allocator_type())
		: _alloc(alloc), _container(0), _capacity(0), _size(0) {
		_container = _alloc.allocate(n);
		_capacity = n;
		for (size_type i=0; i<n; i++)
			_alloc.construct(_container + i, val);
	}
	template<typename Iter>
	vector(Iter first, Iter last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<Iter>::value, Iter>::type* = 0)
		: _alloc(alloc), _container(0), _capacity(0), _size(0) {
		insert(_container, first, last);
	}
	vector(const vector& a) {

	}
	~vector() {}

	vector& operator=(const vector& a) {

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
				_alloc.destroy();
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
			throw std::length_error("vector::reserve");
		if (n > _capacity) {
			pointer _new_container = _alloc.allocate(n);
			for (size_type i=0; i<_size; i++) {
				_alloc.construct(_new_container + i, *(_container + i));
				_alloc.destroy(_container + i);
			}
			if (_container != 0)
				_alloc.deallocate(_container, _capacity);
			_container = _new_container;
		}
		_capacity = n;
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
			throw std::out_of_range("vector:at");
		return *(_container + n);
	}
	const_reference at(size_type n) const {
		if (n >= _size)
			throw std::out_of_range("vector:at");
		return *(_container + n);
	}
	reference front() {
		return *(_container);
	}
	const_reference front() const {
		return *(_container);
	}
	reference back() {
		if (_size > 0)
			return *(_container + _size - 1);
		return *(_container);
	}
	const_reference back() const {
		if (_size > 0)
			return *(_container + _size - 1);
		return *(_container);
	}

	// Modifiers:

	template<typename InputIterator>
	void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0) {
		clear();
		size_type d_size = std::distance(first, last);
		if (d_size <= _capacity)
			for (size_type i=0; i< d_size; i++)
				_alloc.construct(_container + i, *(first + i));
		else {
			reserve(d_size);
			for (size_type i=0; i< d_size; i++)
				_alloc.construct(_container + i, *(first + i));
		}
	}
	void assign(size_type n, const value_type& val) {
		clear();
		if (n <= _capacity)
			for (size_type i=0; i<n; i++)
				_alloc.construct(_container, val);
		else {
			reserve(n);
			for (size_type i=0; i<n; i++)
				_alloc.construct(_container, val);
		}
	}
	void push_back(const value_type& val) {
		if (_size == _capacity) {
			if (_size == 0)
				reserve(1);
			else
				reserve(_capacity * 2);
		}
		_alloc.construct(_container + _size, val);
		_size++;
	}
	void pop_back() {
		_alloc.destroy(_container + --_size);
	}
	//void reserve(size_type n) {
	//	if (n > max_size())
	//		throw std::length_error("vector::reserve");
	//	if (n > _capacity) {
	//		pointer _new_container = _alloc.allocate(n);
	//		for (size_type i=0; i<_size; i++) {
	//			_alloc.construct(_new_container + i, *(_container + i));
	//			_alloc.destroy(_container + i);
	//		}
	//		if (_container != 0)
	//			_alloc.deallocate(_container, _capacity);
	//		_container = _new_container;
	//	}
	//	_capacity = n;
	//}
	iterator insert(iterator position, const value_type& val) {
		size_type rlen = (_container + _size) - &(*position);
		size_type llen = &(*position) - _container;
		pointer _new_container = _container;
		size_type _new_capacity = _capacity;
		if (_size == max_size())
			throw std::length_error("vector::insert(single element)");
		if (_size == 0) {
			_new_container = _alloc.allocate(1);
			_new_capacity = 1;
		} else if (_size == _capacity) {
			_new_container = _alloc.allocate(_capacity * 2);
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
			_alloc.destroy(_container + _size - i - 1);
		}
		// 새로운 값 추가
		_alloc.construct(_new_container + llen, val);
		if (_container != _new_container)
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
			throw std::length_error("vector::insert(fill)");
		if (_size + n > _capacity) {
			if (_size + n < _capacity * 2) {
				_new_container = _alloc.allocate(_capacity * 2);
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
			_alloc.construct(_new_container + _size-1 + n - i, *(_container + _size-1 - i);
			_alloc.destroy(_container + _size-1 - i);
		}
		// 새로운 값 추가
		for (size_type i=0; i<n; i++)
			_alloc.construct(_new_container + llen + i, val);
		if (_container != _new_container)
			_alloc.deallocate(_container, _capacity);
		_container = _new_container;
		_capacity = _new_capacity;
		_size += n;
	}
	template <typename InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = 0) {
		size_type rlen = (_container + _size) - &(*position);
		size_type llen = &(*position) - _container;
		size_type num = std::distance(first, last);
		size_type after_size = num + _size;
		if (_size + num > max_size())
			throw std::length_error("vector::insert(range)");
		if (_size + num > _capacity) {
			if (_size + num < _capacity * 2)
				reserve(_capacity * 2);
			else
				reserve(_size + num);
		}
		iterator end_iter = end();
		for (size_type i=0; i<rlen; i++) {
			_alloc.construct(&(*(end_iter + (num-1) - i)), *(end_iter - i - 1));
			_alloc.destroy(&(*(end_iter - i - 1)));
		}
		for (size_type i=0; i<num; i++)
			_alloc.construct(_container + llen + i, *(first + i));
		_size += num;
	}

	void clear() {
		for (size_type i=0; i<_size; i++)
			_alloc.destroy(_container + i);
	}

};

}

#endif
