/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:45:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 14:58:36 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void	HumanB::attack() {
	std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &w) {
	this->w = &w;
}

HumanB::HumanB(std::string name) {
	this->name = name;
}

HumanB::~HumanB() {
	std::cout << "delete: " << this->name << std::endl;
}
