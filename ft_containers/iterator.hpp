/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:04:36 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/18 19:35:14 by minskim2         ###   ########.fr       */
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

template <typename Category, typename T, typename Distance = std::ptrdiff_t, typename Pointer = T*, typename Reference = T&>
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
	typedef std::ptrdiff_t				difference_type;
	typedef T*							pointer;
	typedef T&							reference;
};

template <typename T>
struct iterator_traits<const T*>
{
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef std::ptrdiff_t				difference_type;
	typedef const T*					pointer;
	typedef const T&					reference;
};

template<typename Iterator>
class reverse_iterator
	: iterator<typename iterator_traits<Iterator>::iterator_category, typename iterator_traits<Iterator>::value_type> {
public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename iterator_traits<Iterator>::value_type			value_type;
	typedef typename iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename iterator_traits<Iterator>::pointer				pointer;
	typedef typename iterator_traits<Iterator>::reference			reference;

private:
	iterator_type _iter;

public:
	reverse_iterator() : _iter() {}
	explicit reverse_iterator(iterator_type it) : _iter(it) {}
	template<typename Iter>
	reverse_iterator(const reverse_iterator<Iter>& rev_it) : _iter(rev_it.base()) {}

	iterator_type base() const {
		return _iter;
	}

	reference operator*() const {
		iterator_type tmp = _iter;
		return *(--tmp);
	}
	reverse_iterator operator+(difference_type n) const {
		reverse_iterator tmp(*this);
		return tmp += n;
	}
	reverse_iterator& operator++() {
		--_iter;
		return *this;
	}
	reverse_iterator operator++(int) {
		reverse_iterator tmp(*this);
		--_iter;
		return tmp;
	}
	reverse_iterator& operator+=(difference_type n) {
		_iter -= n;
		return *this;
	}
	reverse_iterator operator-(difference_type n) const {
		reverse_iterator tmp(*this);
		return tmp -= n;
	}
	reverse_iterator& operator--() {
		++_iter;
		return *this;
	}
	reverse_iterator operator--(int) {
		reverse_iterator tmp(*this);
		++_iter;
		return tmp;
	}
	reverse_iterator& operator-=(difference_type n) {
		_iter += n;
		return *this;
	}
	pointer operator->() const {
		return &(operator*());
	}
	reference operator[](difference_type n) const {
		iterator_type tmp = _iter;
		return *(tmp - n - 1);
	}
};

template<typename Iterator>
bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return lhs.base() == rhs.base();
}
template<typename Iterator>
bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return lhs.base() != rhs.base();
}
template<typename Iterator>
bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return lhs.base() > rhs.base();
}
template<typename Iterator>
bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return lhs.base() >= rhs.base();
}
template<typename Iterator>
bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return lhs.base() < rhs.base();
}
template<typename Iterator>
bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return lhs.base() <= rhs.base();
}

template <class Iterator>
reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
  const reverse_iterator<Iterator>& rev_it) {
	return rev_it + n;
}
template <class Iterator>
typename reverse_iterator<Iterator>::difference_type operator- (
  const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
	return rhs.base() - lhs.base();
}

}

#endif
