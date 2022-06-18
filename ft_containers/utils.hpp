/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 21:29:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/17 21:38:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include "iterator.hpp"

namespace ft {

template<typename InputIterator>
typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last) {
	typename iterator_traits<InputIterator>::difference_type diff = 0;
	typename iterator_traits<InputIterator>::difference_type sign = 1;
	if (first > last) {
		InputIterator tmp = first;
		first = last;
		last = tmp;
		sign = -1;
	}
	for (;first != last; first++, diff++) {	}
	return sign * diff;
}

}

#endif
