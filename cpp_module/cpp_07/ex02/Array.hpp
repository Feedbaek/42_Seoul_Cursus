/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:53:52 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/13 16:18:39 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
private:
	T*	arr;
	std::size_t _size;

public:
	Array(): arr(NULL), _size(0) {
	}
	Array(std::size_t n): arr(NULL), _size(n) {
		if (this->_size)
			this->arr = new T[this->_size];
	}
	Array(cosnt Array& a): arr(NULL), _size(a._size) {
		if (this->_size)
			this->arr = new T[this->_size];
		for (std::size_t i=0; i<this->_size; i++) {
			this->arr[i] = a->arr[i];
		}
	}
	~Array() {
		delete[] arr;
	}

	Array&	operator=(const Array& a) {
		if (this != &a) {
			if (this->_size) {
				delete[] this->arr;
				this->arr = NULL;
			}
			this->_size = a._size;
			if (this->_size)
				this->arr = new T[this->_size];
			for (std::size_t i=0; i<this->_size; i++) {
				this->arr[i] = a.arr[i];
			}
		}
		return *this;
	}

	std::size_t	size() const {
		return (this->_size);
	}
};

#endif
