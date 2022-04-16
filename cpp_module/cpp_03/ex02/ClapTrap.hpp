/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:11:11 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 16:11:21 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
protected:
	std::string	name;
	unsigned int	hp;
	unsigned int	energy;
	unsigned int	damage;

	bool	check_dead(void);
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &a);
	~ClapTrap();

	ClapTrap	&operator=(const ClapTrap &a);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getDamage(void) const;
};

#endif
