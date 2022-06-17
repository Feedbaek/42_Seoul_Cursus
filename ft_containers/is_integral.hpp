/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:27:25 by minskim2          #+#    #+#             */
/*   Updated: 2022/06/17 16:20:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

template<typename T>
struct is_integral {
	typedef T type;
	const static bool value = false;
};

template<>
struct is_integral<bool> {
	typedef bool type;
	const static bool value = true;
};
template<>
struct is_integral<char> {
	typedef char type;
	const static bool value = true;
};
template<>
struct is_integral<wchar_t> {
	typedef wchar_t type;
	const static bool value = true;
};
template<>
struct is_integral<signed char> {
	typedef signed char type;
	const static bool value = true;
};
template<>
struct is_integral<short int> {
	typedef short int type;
	const static bool value = true;
};
template<>
struct is_integral<int> {
	typedef int type;
	const static bool value = true;
};
template<>
struct is_integral<long int> {
	typedef long int type;
	const static bool value = true;
};
template<>
struct is_integral<long long int> {
	typedef long long int type;
	const static bool value = true;
};
template<>
struct is_integral<unsigned char> {
	typedef unsigned char type;
	const static bool value = true;
};
template<>
struct is_integral<unsigned short int> {
	typedef unsigned short int type;
	const static bool value = true;
};
template<>
struct is_integral<unsigned int> {
	typedef unsigned int type;
	const static bool value = true;
};
template<>
struct is_integral<unsigned long int> {
	typedef unsigned long int type;
	const static bool value = true;
};
template<>
struct is_integral<unsigned long long int> {
	typedef unsigned long long int type;
	const static bool value = true;
};

}

#endif
