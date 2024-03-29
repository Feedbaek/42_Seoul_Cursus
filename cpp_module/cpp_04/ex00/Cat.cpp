/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:54:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 15:27:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor\n";
	this->type = "Cat";
}
Cat::Cat(const Cat &a) :Animal(a) {
	*this = a;
	std::cout << "Cat copy constructor\n";
}
Cat::~Cat() {
	std::cout << "Cat destructor\n";
}

Cat &Cat::operator=(const Cat &a) {
	this->type = a.type;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "meow~\n";
}
