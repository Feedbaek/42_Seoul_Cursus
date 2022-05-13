/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:41:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/12 17:00:33 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	iter(T* array, std::size_t len, void (*forEach)(const T&)) {
	for (std::size_t i=0; i<len; i++)
		forEach(array[i]);
}

template<typename T>
void	std_cout(const T& a) {
	std::cout << a << " ";
}

#endif
