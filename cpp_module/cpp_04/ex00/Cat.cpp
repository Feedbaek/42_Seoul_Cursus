/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:54:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 16:36:59 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
}
Cat::Cat(const Cat &a) {
	*this = a;
}
Cat::~Cat() {
}

Cat &Cat::operator=(const Cat &a) {
	this->type = a.type;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "meow~\n";
}
