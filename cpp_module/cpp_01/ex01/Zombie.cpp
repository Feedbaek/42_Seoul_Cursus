/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:54:54 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 01:34:30 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::initialize(std::string name) {
	this->name = name;
}

Zombie::Zombie(void) {
}

Zombie::~Zombie(void) {
	std::cout << this->name << " dead\n";
}
