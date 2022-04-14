/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:45:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 16:39:23 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack() {
	if (this->w)
		std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
	else
		std::cout << this->name << " attacks with his fist " << std::endl;
}

void	HumanB::setWeapon(Weapon &w) {
	this->w = &w;
}

HumanB::HumanB(std::string name) {
	this->name = name;
	this->w = NULL;
}

HumanB::~HumanB() {
	std::cout << "delete: " << this->name << std::endl;
}
