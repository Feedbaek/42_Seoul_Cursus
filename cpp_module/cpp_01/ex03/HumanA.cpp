/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:28:11 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 14:58:24 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack() {
	std::cout << this->name << " attacks with his " << this->w->getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &w) {
	this->name = name;
	this->w = &w;
}

HumanA::~HumanA() {
	std::cout << "delete: " << this->name << std::endl;
}
