/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 15:01:57 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog() {
	this->type = "WrongDog";
	std::cout << "WrongDog default constructor\n";
}
WrongDog::WrongDog(const WrongDog &a) :WrongAnimal() {
	*this = a;
	std::cout << "WrongDog copy constructor\n";
}
WrongDog::~WrongDog() {
	std::cout << "WrongDog destructor\n";
}

WrongDog &WrongDog::operator=(const WrongDog &a) {
	this->type = a.type;
	return (*this);
}

void	WrongDog::makeSound() const {
	std::cout << "bark!\n";
}
