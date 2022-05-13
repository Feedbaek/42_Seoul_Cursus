/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:26:39 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/11 12:48:58 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

uintptr_t	serialize(Data* ptr) {
	uintptr_t ret = reinterpret_cast<uintptr_t>(new char[sizeof(int)]);
	*(reinterpret_cast<int*>(ret)) = ptr->value;
	return ret;
}

Data*		deserialize(uintptr_t raw) {
	Data*	ret = new Data;
	ret->value = *reinterpret_cast<int*>(raw);
	return ret;
}
