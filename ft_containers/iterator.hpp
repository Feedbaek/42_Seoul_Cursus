/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:04:36 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/11 00:10:04 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <memory>

namespace ft {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template <typename Category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
struct iterator {
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
	typedef Category	iterator_category;
};

template<typename Iter>
struct iterator_traits {
	typedef typename Iter::iterator_category	iterator_category;
	typedef typename Iter::value_type			value_type;
	typedef typename Iter::difference_type		difference_type;
	typedef typename Iter::pointer				pointer;
	typedef typename Iter::reference			reference;
};

template<typename T>
struct iterator_traits<T*>	// 포인터일 경우를 특수화
{
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef T*							pointer;
	typedef T&							reference;
};

template <typename T>
struct iterator_traits<const T*>
{
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef const T*					pointer;
	typedef const T&					reference;
};

template<typename Iter>
class vector_reverse_iterator : public Iter {
public:
	typedef Iter iterator_type;
	typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iter>::value_type			value_type;
	typedef typename iterator_traits<Iter>::difference_type		difference_type;
	typedef typename iterator_traits<Iter>::pointer				pointer;
	typedef typename iterator_traits<Iter>::reference			reference;

public:
	vector_reverse_iterator() : Iter() {}
	vector_reverse_iterator(pointer a): Iter(a) {}
	vector_reverse_iterator(const vector_reverse_iterator& a) : Iter(a) {}
	vector_reverse_iterator& operator=(const vector_reverse_iterator& a) {
		this->p = a.p;
		return *this;
	}
	~vector_reverse_iterator() {}
	virtual vector_reverse_iterator& operator++() {
		--(this->p);
		return *this;
	}
	virtual vector_reverse_iterator operator++(int) {
		vector_reverse_iterator tmp(*this);
		--(this->p);
		return tmp;
	}
	virtual vector_reverse_iterator& operator--() {
		++(this->p);
		return *this;
	}
	virtual vector_reverse_iterator operator--(int) {
		vector_reverse_iterator tmp(*this);
		++(this->p);
		return tmp;
	}
	virtual vector_reverse_iterator operator+(int value) {
		vector_reverse_iterator tmp(*this);
		return tmp - value;
	}
	virtual vector_reverse_iterator operator-(int value) {
		vector_reverse_iterator tmp(*this);
		return tmp + value;
	}
	virtual vector_reverse_iterator& operator+=(int value) {
		this->p -= value;
		return *this;
	}
	virtual vector_reverse_iterator& operator-=(int value) {
		this->p += value;
		return *this;
	}
	virtual reference operator[](int value) {
		return *(this->p - value);
	}
	virtual const reference operator[](int value) const {
		return *(this->p - value);
	}
};

}

#endif