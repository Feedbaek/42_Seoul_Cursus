/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:12:16 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 17:12:46 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() :ClapTrap() {
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap default constructor " << this->name << " called\n";
}
FragTrap::FragTrap(std::string name) :ClapTrap(name) {
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap string constructor " << this->name << " called\n";
}
FragTrap::FragTrap(const FragTrap &a) :ClapTrap(a) {
	std::cout << "FragTrap copy constructor " << this->name << " called\n";
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor " << this->name << " called\n";
}
FragTrap &FragTrap::operator= (const FragTrap &a) {
	ClapTrap::operator=(a);
	std::cout << "FragTrap operator= " << this->name << " called\n";
	return (*this);
}
void	FragTrap::highFivesGuys(void) {
	if (check_dead())
		return ;
	std::cout << "FragTrap " << this->name << " positive high fives request\n";
}
