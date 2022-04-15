/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:00:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/15 15:23:38 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	bool	guard_mode;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap &a);
	~ScavTrap();
	ScavTrap &operator= (ScavTrap &a);

	void	guardGate();
};

#endif
