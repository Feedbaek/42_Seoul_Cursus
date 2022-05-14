/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:37:45 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/14 20:01:12 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <stdexcept>
# include <deque>
# include <list>
# include <vector>

template<typename T>
typename T::iterator easyfind(T* container, int value) {
	typename T::iterator iter = std::find(container->begin(), container->end(), value);
	if (iter == container->end())
		throw std::runtime_error(std::string("Not Found"));
	return iter;
}

#endif
