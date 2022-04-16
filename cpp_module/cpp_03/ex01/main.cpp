/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:24:49 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 15:25:41 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("a");
	ScavTrap	b("b");

	std::cout << std::endl;

	a.attack("b");
	b.takeDamage(a.getDamage());

	std::cout << std::endl;

	b.attack("a");
	a.takeDamage(b.getDamage());

	std::cout << std::endl;

	a.attack("b");
	b.takeDamage(a.getDamage());

	std::cout << std::endl;

	b.attack("a");
	a.takeDamage(b.getDamage());

	std::cout << std::endl;

	b.guardGate();

	std::cout << std::endl;
	return (0);
}
