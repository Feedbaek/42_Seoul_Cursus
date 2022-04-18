/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/17 21:07:02 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal default constructor\n";
	this->type = "WrongAnimal";
}
WrongAnimal::WrongAnimal(const WrongAnimal &a) {
	std::cout << "WrongAnimal copy constructor\n";
	*this = a;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &a) {
	this->type = a.type;
	return (*this);
}

void	WrongAnimal::makeSound() const {
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}
