/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:59:50 by minskim2          #+#    #+#             */
/*   Updated: 2022/07/12 21:01:22 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>

# include "utils.hpp"
# include "iterator.hpp"
# include "pair.hpp"
# include "red_black_tree.hpp"

namespace ft {

template<typename Key, typename T, typename Compare = std::less<Key>>
class map {
public:
	typedef Key								key_type;
	typedef T								mapped_type;
	typedef pair<Key, T>					value_type;
	typedef size_t							size_type;
	typedef Compare							key_compare;
	typedef std::allocator<value_type>		allocator_type;

	class value_compare : public std::binary_function<value_type, value_type, bool> {
		friend class map;
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator()(const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
	typedef tree_iterator<value_type>					iterator;
	typedef tree_const_iterator<value_type>				const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;


private:

public:
	map();
	~map();
};

}

#endif
