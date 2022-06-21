/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:43:09 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/21 21:23:26 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

template<typename T1 ,typename T2>
struct pair {
	typedef T1	first_type;
	typedef T2	second_type;

	first_type first;
	second_type second;

	pair() : first(), second() {}
	template<typename U, typename V>
	pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}
	pair(const first_type& a, const second_type& b) : first(a), second(b) {}

	pair& operator=(const pair& pr) {
		if (this == &pr)
			return *this;
		first = pr.first;
		second = pr.second;
		return *this;
	}
};

template<typename T1, typename T2>
pair<T1, T2> make_pair(T1 x, T2 y) {
	return pair<T1, T2>(x, y);
}

template<typename T1, typename T2>
bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return lhs.first==rhs.first && lhs.second==rhs.second;
}
template<typename T1, typename T2>
bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return !(lhs==rhs);
}
template<typename T1, typename T2>
bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
}
template<typename T1, typename T2>
bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return !(rhs<lhs);
}
template<typename T1, typename T2>
bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return rhs<lhs;
}
template<typename T1, typename T2>
bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
	return !(lhs<rhs);
}

#endif
