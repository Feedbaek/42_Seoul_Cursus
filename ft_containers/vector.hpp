/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:04:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/09 22:54:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>

# include "iterator.hpp"

namespace ft {

template<typename T>
class vector_iterator {
public:
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef value_type&					reference;
	typedef const value_type&			const_reference;
	typedef value_type*					pointer;
	typedef const value_type*			const_pointer;
	typedef std::ptrdiff_t				difference_type;

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
	const_reference operator*() const {
		return *p;
	}
	pointer operator->() {
		return p;
	}
	const_pointer operator->() const {
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
	virtual const_reference operator[](int value) const {
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
	typedef size_t size_type;

private:
	allocator_type _alloc;
	pointer _container;
	size_type _capacity;
	size_type _size;

public:
	explicit vector() : _container(0), _capacity(0), _size(0) {}
	explicit vector(size_type n, const value_type& val=value_type()) : _container(0), _capacity(0), _size(0) {

	}
	template<typename Iter>
	vector(Iter first, Iter last) {

	}
	vector(const vector& a) {

	}
	~vector() {}

	vector& operator=(const vector& a) {

	}

	iterator begin() {
		return iterator(this->_container);
	}
	const_iterator begin() const {
		return const_iterator(this->_container)
	}
	iterator end() {
		return iterator(this->_container + this->_size);
	}
	const_iterator end() const {
		return const_iterator(this->_container + this->_size)
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

	size_type size() const {
		return this->_size;
	}
};

}

#endif
