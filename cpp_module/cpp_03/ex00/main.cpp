/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:09:32 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/15 13:52:16 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	a("a");
	ClapTrap	b("b");
	ClapTrap	c("c");

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;
	c.attack("b");
	b.takeDamage(c.getDamage());
	std::cout << std::endl;
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	a.beRepaired(25);
	std::cout << std::endl;
	return (0);
}
