/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 21:07:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal default constructor\n";
	this->type = "Animal";
}
Animal::Animal(const Animal &a) {
	std::cout << "Animal copy constructor\n";
	*this = a;
}
Animal::~Animal() {
	std::cout << "Animal destructor\n";
}

Animal &Animal::operator=(const Animal &a) {
	this->type = a.type;
	return (*this);
}

void	Animal::makeSound() const {
}

std::string	Animal::getType() const {
	return (this->type);
}
