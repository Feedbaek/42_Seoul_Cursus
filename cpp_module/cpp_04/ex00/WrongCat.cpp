/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:54:18 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/18 15:02:07 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat default constructor\n";
	this->type = "WrongCat";
}
WrongCat::WrongCat(const WrongCat &a) :WrongAnimal() {
	*this = a;
	std::cout << "WrongCat copy constructor\n";
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor\n";
}

WrongCat &WrongCat::operator=(const WrongCat &a) {
	this->type = a.type;
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "meow~\n";
}
