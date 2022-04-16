/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 14:59:52 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 15:42:13 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() :ClapTrap() {
	this->guard_mode = false;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap default constructor " << this->name << " called\n";
}
ScavTrap::ScavTrap(std::string name) :ClapTrap(name) {
	this->guard_mode = false;
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap string constructor " << this->name << " called\n";
}
ScavTrap::ScavTrap(const ScavTrap &a) :ClapTrap(a) {
	this->guard_mode = a.guard_mode;
	std::cout << "ScavTrap copy constructor " << this->name << " called\n";
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor " << this->name << " called\n";
}
ScavTrap &ScavTrap::operator= (const ScavTrap &a) {
	ClapTrap::operator=(a);
	this->guard_mode = a.guard_mode;
	std::cout << "ScavTrap operator= " << this->name << " called\n";
	return (*this);
}

void	ScavTrap::attack(std::string const &target) {
	if (check_dead())
		return ;
	std::cout << "ScavTrap "+this->name+" attacks "+target+", causing " << this->damage << " points of damage!\n";
	this->energy--;
	if (this->energy == 0)
		std::cout << this->name+" is dead\n";
}

void	ScavTrap::guardGate() {
	if (check_dead())
		return ;
	if (this->guard_mode)
		std::cout << "ScavTrap "+this->name+" is already Gate keeper mode\n";
	else {
		std::cout << "ScavTrap "+this->name+" switch to Gate keeper mode\n";
		this->guard_mode = true;
	}
}
