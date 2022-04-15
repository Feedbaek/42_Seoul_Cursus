/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:08:54 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/15 12:08:19 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

const std::string	&Weapon::getType() {
	return (this->type);
}
void	Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::Weapon(std::string	type) {
	this->type = type;
}

Weapon::~Weapon() {
	std::cout << "delete: " << this->type << std::endl;
}
