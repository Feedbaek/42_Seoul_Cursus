/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:58:24 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/11 19:15:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template<typename T>
void	swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename T>
T&		min(T& a, T& b) {
	if (a < b)
		return a;
	else
		return b;
}

template<typename T>
T&		max(T& a, T& b) {
	if (a > b)
		return a;
	else
		return b;
}

#endif
