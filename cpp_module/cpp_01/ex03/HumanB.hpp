/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minskim2 <minskim2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 14:45:31 by minskim2          #+#    #+#             */
/*   Updated: 2022/04/10 14:52:44 by minskim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

class HumanB {
private:
	std::string	name;
	Weapon	*w;
public:
	void	attack();
	void	setWeapon(Weapon &w);
	HumanB(std::string name);
	~HumanB();
};
