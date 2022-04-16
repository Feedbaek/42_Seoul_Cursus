/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:09:43 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 15:41:03 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

bool	ClapTrap::check_dead(void) {
	if (this->hp == 0 || this->energy == 0) {
		std::cout << "ClapTrap "+this->name+" is already dead\n";
		return (true);
	}
	return (false);
}

ClapTrap::ClapTrap() {
	this->name = "";
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap default constructor Unknown called\n";
}
ClapTrap::ClapTrap(std::string name) {
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->damage = 0;
	std::cout << "ClapTrap string constructor " << this->name << " called\n";
}
ClapTrap::ClapTrap(const ClapTrap &a) {
	*this = a;
	std::cout << "ClapTrap copy constructor " << this->name << " called\n";
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor " << this->name << " called\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &a) {
	this->name = a.name;
	this->hp = a.hp;
	this->energy = a.energy;
	this->damage = a.damage;
	std::cout << "ClapTrap operator= " << this->name << " called\n";
	return (*this);
}

void	ClapTrap::attack(const std::string &target) {
	if (check_dead())
		return ;
	std::cout << "ClapTrap "+this->name+" attacks "+target+", causing " << this->damage << " points of damage!\n";
	this->energy--;
	if (this->energy == 0)
		std::cout << "ClapTrap "+this->name+" is dead\n";
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (check_dead())
		return ;
	std::cout << "ClapTrap "+this->name+" takeDameges " << amount << std::endl;
	if (this->hp > amount)
		this->hp -= amount;
	else {
		this->hp = 0;
		std::cout << "ClapTrap "+this->name+" is dead\n";
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (check_dead())
		return ;
	if (this->hp + amount > 10)
		this->hp = 10;
	else
		this->hp += amount;
	std::cout << "ClapTrap "+this->name+" beRepaired, and current Hit points are " << this->hp << std::endl;
	this->energy--;
	if (this->energy == 0)
		std::cout << "ClapTrap "+this->name+" is dead\n";
}

unsigned int	ClapTrap::getDamage(void) const {
	return (this->damage);
}
