/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:04:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/06 19:00:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>

namespace ft {


template<typename T>
class vector {
private:
	class iterator {
	public:
		typedef T value_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;
		typedef std::ptrdiff_t difference_type;

	protected:
		pointer p;

	public:
		iterator(): p(0) {}
		iterator(pointer a): p(a) {}
		iterator(const iterator& a) : p(a.p) {}
		iterator& operator=(cosnt iterator& a) {
			p = a.p;
			return *this;
		}
		bool operator==(const iterator& a) const {
			return p == a.p;
		}
		bool operator!=(const iterator& a) const {
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
		iterator& operator++() {
			++p;
			return *this;
		}
		iterator operator++(int) {
			iterator tmp(*this);
			++p;
			return tmp;
		}
		iterator& operator--() {
			--p;
			return *this;
		}
		iterator operator--(int) {
			iterator tmp(*this);
			--p;
			return tmp;
		}

	};
public:
	typedef T value_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef
	vector();
	~vector();
};

}

#endif
