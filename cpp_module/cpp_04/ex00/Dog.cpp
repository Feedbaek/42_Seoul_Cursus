/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 16:37:10 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
}
Dog::Dog(const Dog &a) {
	*this = a;
}
Dog::~Dog() {
}

Dog &Dog::operator=(const Dog &a) {
	this->type = a.type;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "bark!\n";
}
