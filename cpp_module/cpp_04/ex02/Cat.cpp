/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:54:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/22 16:33:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat default constructor\n";
	this->type = "Cat";
	this->brain = new Brain();
}
Cat::Cat(const Brain &brain) {
	std::cout << "Cat brain constructor\n";
	this->type = "Cat";
	this->brain = new Brain();
	*this->brain = brain;
}
Cat::Cat(const Cat &a) :Animal(a) {
	std::cout << "Cat copy constructor\n";
	this->brain = new Brain();
	*this = a;
}
Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor\n";
}

Cat &Cat::operator=(const Cat &a) {
	this->type = a.type;
	*this->brain = *a.brain;
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "meow~\n";
}
void	Cat::setter(std::string str, int n) {
	this->brain->setter(str, n);
}

std::string	Cat::getter() {
	return (this->brain->getter());
}
