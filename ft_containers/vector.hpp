/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:04:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/07 17:46:41 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>

# include "iterator.hpp"

namespace ft {

template<typename T>
class vector_iterator : iterator<random_access_iterator_tag, T> {
public:
	//typedef T value_type;
	//typedef value_type& reference;
	//typedef const value_type& const_reference;
	//typedef value_type* pointer;
	//typedef const value_type* const_pointer;
	//typedef std::ptrdiff_t difference_type;

protected:
	pointer p;

public:
	vector_iterator(): p(0) {}
	vector_iterator(pointer a): p(a) {}
	vector_iterator(const vector_iterator& a) : p(a.p) {}
	vector_iterator& operator=(cosnt vector_iterator& a) {
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
	vector_iterator operator+(int value) {
		vector_iterator tmp(*this);
		tmp->p += value;
		return value;
	}
	vector_iterator operator-(int value) {
		vector_iterator tmp(*this);
		tmp->p -= value;
		return tmp;
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
	vector_iterator& operator+=(int value) {
		p += value;
		return *this;
	}
	vector_iterator& operator-=(int value) {
		p -= value;
		return *this;
	}
	reference operator[](int value) {
		return *(p + value);
	}
	const_reference operator[](int value) const {
		return *(p + value);
	}
};

template<typename T>
class vector {
private:


public:
	typedef T value_type;
	typedef std::allocator<value_type> allocator_type;
	typedef allocator_type::reference reference;
	typedef allocator_type::const_reference const_reference;
	typedef allocator_type::pointer pointer;
	typedef allocator_type::const_pointer const_pointer;
	typedef iterator<value_type> iterator;
	typedef iterator<const value_type> const_iterator;

	vector();
	~vector();
};

}

#endif
