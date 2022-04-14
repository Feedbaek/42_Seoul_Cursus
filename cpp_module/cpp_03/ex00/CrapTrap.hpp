/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CrapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:10:02 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/14 22:26:15 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRAPTRAP_HPP
# define CRAPTRAP_HPP

#include <iostream>

class CrapTrap {
private:
	std::string	name;
	unsigned int	hp;
	unsigned int	energy;
	unsigned int	damage;
public:
	CrapTrap();
	CrapTrap(std::string name);
	CrapTrap(const CrapTrap &a);
	~CrapTrap();

	CrapTrap	&operator=(const CrapTrap &a);

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getDamage(void) const;
};

#endif
