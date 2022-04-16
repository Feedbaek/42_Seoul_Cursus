/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:00:06 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/16 17:31:31 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class ScavTrap :public ClapTrap {
private:
	bool	guard_mode;
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &a);
	~ScavTrap();

	ScavTrap &operator= (const ScavTrap &a);

	void	attack(std::string const &target);
	void	guardGate();
};

#endif
