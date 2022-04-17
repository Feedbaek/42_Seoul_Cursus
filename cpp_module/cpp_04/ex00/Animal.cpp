/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 16:36:51 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	this->type = "Animal";
}
Animal::Animal(const Animal &a) {
	*this = a;
}
Animal::~Animal() {
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
