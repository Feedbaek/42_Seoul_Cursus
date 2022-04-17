/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 21:08:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	std::cout << "Dog default constructor\n";
}
Dog::Dog(const Dog &a) {
	*this = a;
	std::cout << "Dog copy constructor\n";
}
Dog::~Dog() {
	std::cout << "Dog destructor\n";
}

Dog &Dog::operator=(const Dog &a) {
	this->type = a.type;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "bark!\n";
}
