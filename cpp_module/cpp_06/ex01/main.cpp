/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:14:08 by minskim2          #+#    #+#             */
/*   Updated: 2022/05/11 13:08:06 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

int	main() {
	Data* data = new Data;
	Data* ret;
	uintptr_t ptr;

	data->value = 42;
	ptr = serialize(data);
	ret = deserialize(ptr);

	std::cout <<"origin: " << data->value << std::endl;
	std::cout <<"serialze: " << ret->value << std::endl;
	delete data;
	delete reinterpret_cast<char *>(ptr);
	delete ret;
	return 0;
}
