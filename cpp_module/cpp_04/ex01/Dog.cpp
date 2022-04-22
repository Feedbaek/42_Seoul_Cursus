/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:45:05 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/22 16:32:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog default constructor\n";
	this->type = "Dog";
	this->brain = new Brain();
}
Dog::Dog(const Brain &a) {
	std::cout << "Dog copy constructor\n";
	this->brain = new Brain();
	*this->brain = a;
}
Dog::Dog(const Dog &a) :Animal(a){
	std::cout << "Dog copy constructor\n";
	this->brain = new Brain();
	*this = a;
}
Dog::~Dog() {
	delete this->brain;
	std::cout << "Dog destructor\n";
}

Dog &Dog::operator=(const Dog &a) {
	this->type = a.type;
	*this->brain = *a.brain;
	return (*this);
}

void	Dog::makeSound() const {
	std::cout << "bark!\n";
}
void	Dog::setter(std::string str, int n) {
	this->brain->setter(str, n);
}

std::string	Dog::getter() {
	return (this->brain->getter());
}
