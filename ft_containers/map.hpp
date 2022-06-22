/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:59:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/22 21:27:28 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>

# include "utils.hpp"
# include "iterator.hpp"
# include "pair.hpp"

namespace ft {

template<typename T>
class map_iterator : public iterator<bidirectional_iterator_tag, T> {
private:

};

template<typename Key, typename T, typename Compare = std::less<Key>>
class map {
public:
	typedef Key									key_type;
	typedef T									mapped_type;
	typedef pair<const key_type, mapped_type>	value_type;
	typedef Compare								key_compare;

	class value_compare : public std::binary_function<value_type, value_type, bool> {
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	typedef allocator<value_type>				allocator_type;
	typedef allocator_type::reference			reference;
	typedef allocator_type::const_reference		const_reference;
	typedef allocator_type::pointer				pointer;
	typedef allocator_type::const_pointer		const_pointer;



private:

public:
	map();
	~map();
};

}

#endif
